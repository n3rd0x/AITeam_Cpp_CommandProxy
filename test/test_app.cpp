#include "app.h"
#include <gtest/gtest.h>
#include <string>

namespace aiteam {

class AppTest : public ::testing::Test {
protected:
    void SetUp() override {
        app_ = std::make_unique<App>();
    }

    std::unique_ptr<App> app_;
};

TEST_F(AppTest, InitWithNoArguments) {
    EXPECT_TRUE(app_->init(0, nullptr));
}

TEST_F(AppTest, InitWithOneArgument) {
    const char* argv[] = { "command" };
    EXPECT_TRUE(app_->init(1, const_cast<char**>(argv)));
}

TEST_F(AppTest, InitWithMultipleArguments) {
    const char* argv[] = { "command", "arg1", "arg2", "arg3" };
    EXPECT_TRUE(app_->init(4, const_cast<char**>(argv)));
}

TEST_F(AppTest, InitReturnsTrue) {
    EXPECT_TRUE(app_->init(0, nullptr));
}

TEST_F(AppTest, RunReturnsFalseWhenNotInitialized) {
    EXPECT_FALSE(app_->run());
}

TEST_F(AppTest, RunReturnsFalseWhenInitialized) {
    ASSERT_TRUE(app_->init(0, nullptr));
    EXPECT_FALSE(app_->run());
}

TEST_F(AppTest, RunAfterInitReturnsFalseTwice) {
    ASSERT_TRUE(app_->init(0, nullptr));
    EXPECT_FALSE(app_->run());
    EXPECT_FALSE(app_->run());
}

TEST_F(AppTest, InitTwiceReturnsTrueSecondTime) {
    EXPECT_TRUE(app_->init(0, nullptr));
    const char* argv[] = { "arg" };
    EXPECT_TRUE(app_->init(1, const_cast<char**>(argv)));
}

TEST_F(AppTest, InitWithEmptyStringArguments) {
    const char* argv[] = { "", " ", "   " };
    EXPECT_TRUE(app_->init(3, const_cast<char**>(argv)));
}

TEST_F(AppTest, RunAlwaysReturnsFalse) {
    ASSERT_TRUE(app_->init(0, nullptr));
    EXPECT_FALSE(app_->run());
    EXPECT_FALSE(app_->run());
    EXPECT_FALSE(app_->run());
}

}  // namespace aiteam