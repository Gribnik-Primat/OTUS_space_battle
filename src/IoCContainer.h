
#include <map>
#include <mutex>
#include <unordered_map>
#include <functional>

class IoCContainer {
private:
    std::unordered_map<std::string, std::function<void*()>> dependencies;
    thread_local static std::unordered_map<std::string, IoCContainer*> scopes;
    static std::mutex scopesMutex;

public:
    template<typename T>
    void Register(const std::string& key) {
        dependencies[key] = []() { return new T(); };
    }

    template<typename T, typename... Args>
    void Register(const std::string& key, Args... args) {
        dependencies[key] = [=]() { return new T(args...); };
    }

    template<typename T>
    T* Resolve(const std::string& key) {
        auto it = dependencies.find(key);
        if (it == dependencies.end())
            throw std::runtime_error("Dependency with key '" + key + "' is not registered.");

        return static_cast<T*>(it->second());
    }

    static IoCContainer& Current(const std::string& scopeId) {
        std::lock_guard<std::mutex> lock(scopesMutex);

        auto it = scopes.find(scopeId);
        if (it != scopes.end())
            return *it->second;

        scopes[scopeId] = new IoCContainer();
        return *scopes[scopeId];
    }

    static void New(const std::string& scopeId) {
        std::lock_guard<std::mutex> lock(scopesMutex);
        scopes[scopeId] = new IoCContainer();
    }

    static void Clear() {
        std::lock_guard<std::mutex> lock(scopesMutex);
        for (auto& pair : scopes)
            delete pair.second;

        scopes.clear();
    }
};
