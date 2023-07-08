#include <gtest/gtest.h>
#include <thread>
#include <mutex>
#include "IoCContainer.h"

TEST(IoCContainerTest, ResolveRegisteredDependency) {
    IoCContainer container;
    container.Register<int>("myDependency", 42);

    int* dependency = container.Resolve<int>("myDependency");

    ASSERT_EQ(*dependency, 42);

    delete dependency;
}

TEST(IoCContainerTest, ResolveUnregisteredDependency) {
    IoCContainer container;

    ASSERT_THROW(container.Resolve<int>("unregisteredDependency"), std::runtime_error);
}

TEST(IoCContainerTest, ThreadSafeResolve) {
    IoCContainer container;
    container.Register<int>("myDependency", 42);

    const int numThreads = 100;
    std::vector<std::thread> threads(numThreads);
    std::mutex mutex;

    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread([&container, &mutex]() {
            std::lock_guard<std::mutex> lock(mutex);
            int* dependency = container.Resolve<int>("myDependency");
            ASSERT_EQ(*dependency, 42);
            delete dependency;
        });
    }

    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }
}
