
#include "sample3-inl.h"
#include "gtest/gtest.h"
namespace {
// To use a test fixture, derive a class from testing::Test.
class QueueTestSmpl3 : public testing::Test {
 protected:  // You should make the members protected s.t. they can be
             // accessed from sub-classes.

  // virtual void SetUp() will be called before each test is run.  You
  // should define it if you need to initialize the variables.
  // Otherwise, this can be skipped.
  void SetUp() override {
    q1_.Enqueue(1);
    q2_.Enqueue(2);
    q2_.Enqueue(3);
  }

  // virtual void TearDown() will be called after each test is run.
  // You should define it if there is cleanup work to do.  Otherwise,
  // you don't have to provide it.
  //
  // virtual void TearDown() {
  // }

  // A helper function that some test uses.
  static int Double(int n) {
    return 2*n;
  }

  // A helper function for testing Queue::Map().
  void MapTester(const Queue<int> * q) {
    // Creates a new queue, where each element is twice as big as the
    // corresponding one in q.
    const Queue<int> * const new_q = q->Map(Double);

    // Verifies that the new queue has the same size as q.
    ASSERT_EQ(q->Size(), new_q->Size());

    // Verifies the relationship between the elements of the two queues.
    for (const QueueNode<int>*n1 = q->Head(), *n2 = new_q->Head();
         n1 != nullptr; n1 = n1->next(), n2 = n2->next()) {
      EXPECT_EQ(2 * n1->element(), n2->element());
    }

    delete new_q;
  }

  // Declares the variables your tests want to use.
  Queue<int> q0_;
  Queue<int> q1_;
  Queue<int> q2_;
};

// When you have a test fixture, you define a test using TEST_F
// instead of TEST.

// Tests the default c'tor.
TEST_F(QueueTestSmpl3, DefaultConstructor) {
  // You can access data in the test fixture here.
  EXPECT_EQ(0u, q0_.Size());
}

// Tests Dequeue().
TEST_F(QueueTestSmpl3, Dequeue) {
  int * n = q0_.Dequeue();
  EXPECT_TRUE(n == nullptr);

  n = q1_.Dequeue();
  ASSERT_TRUE(n != nullptr);
  EXPECT_EQ(1, *n);
  EXPECT_EQ(0u, q1_.Size());
  delete n;

  n = q2_.Dequeue();
  ASSERT_TRUE(n != nullptr);
  EXPECT_EQ(2, *n);
  EXPECT_EQ(1u, q2_.Size());
  n = q2_.Dequeue();
  EXPECT_EQ(3, *n);
  EXPECT_EQ(0u, q2_.Size());
  delete n;
}

TEST_F(QueueTestSmpl3, CheckInitial) {
  int n = q0_.Size();
  EXPECT_TRUE(n == 0);

  n = q1_.Size();
  EXPECT_TRUE(n == 1);

  n = q2_.Size();
  EXPECT_TRUE(n == 2);
}

// Tests the Queue::Map() function.
TEST_F(QueueTestSmpl3, Map) {
  MapTester(&q0_);
  MapTester(&q1_);
  MapTester(&q2_);
}
}  // namespace
