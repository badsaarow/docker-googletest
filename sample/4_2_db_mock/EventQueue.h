
#include <stddef.h>


// EventQueue is a simple queue implemented as a singled-linked list.
//
// The element type must support copy constructor.
template <typename E>  // E is the element type
class EventQueue;

// QueueNode is a node in a EventQueue, which consists of an element of
// type E and a pointer to the next node.
template <typename E>  // E is the element type
class QueueNode {
  friend class EventQueue<E>;

 public:
  // Gets the element in this node.
  const E& element() const { return element_; }

  // Gets the next node in the queue.
  QueueNode* next() { return next_; }
  const QueueNode* next() const { return next_; }

 private:
  // Creates a node with a given element value.  The next pointer is
  // set to NULL.
  explicit QueueNode(const E& an_element)
      : element_(an_element), next_(nullptr) {}

  // We disable the default assignment operator and copy c'tor.
  const QueueNode& operator = (const QueueNode&);
  QueueNode(const QueueNode&);

  E element_;
  QueueNode* next_;
};

template <typename E>  // E is the element type.
class EventQueue {
 public:
  // Creates an empty queue.
  EventQueue() : head_(nullptr), last_(nullptr), size_(0) {}

  // D'tor.  Clears the queue.
  ~EventQueue() { Clear(); }

  // Clears the queue.
  void Clear() {
    if (size_ > 0) {
      // 1. Deletes every node.
      QueueNode<E>* node = head_;
      QueueNode<E>* next = node->next();
      for (; ;) {
        delete node;
        node = next;
        if (node == nullptr) break;
        next = node->next();
      }

      // 2. Resets the member variables.
      head_ = last_ = nullptr;
      size_ = 0;
    }
  }

  // Gets the number of elements.
  size_t Size() const { return size_; }

  // Gets the first element of the queue, or NULL if the queue is empty.
  QueueNode<E>* Head() { return head_; }
  const QueueNode<E>* Head() const { return head_; }

  // Gets the last element of the queue, or NULL if the queue is empty.
  QueueNode<E>* Last() { return last_; }
  const QueueNode<E>* Last() const { return last_; }

  // Adds an element to the end of the queue.  A copy of the element is
  // created using the copy constructor, and then stored in the queue.
  // Changes made to the element in the queue doesn't affect the source
  // object, and vice versa.
  void Enqueue(const E& element) {
    QueueNode<E>* new_node = new QueueNode<E>(element);

    if (size_ == 0) {
      head_ = last_ = new_node;
      size_ = 1;
    } else {
      last_->next_ = new_node;
      last_ = new_node;
      size_++;
    }
  }

  // Removes the head of the queue and returns it.  Returns NULL if
  // the queue is empty.
  E* Dequeue() {
    if (size_ == 0) {
      return nullptr;
    }

    const QueueNode<E>* const old_head = head_;
    head_ = head_->next_;
    size_--;
    if (size_ == 0) {
      last_ = nullptr;
    }

    E* element = new E(old_head->element());
    delete old_head;

    return element;
  }

  // Applies a function/functor on each element of the queue, and
  // returns the result in a new queue.  The original queue is not
  // affected.
  template <typename F>
  EventQueue* Map(F function) const {
    EventQueue* new_queue = new EventQueue();
    for (const QueueNode<E>* node = head_; node != nullptr;
         node = node->next_) {
      new_queue->Enqueue(function(node->element()));
    }

    return new_queue;
  }

 private:
  QueueNode<E>* head_;  // The first node of the queue.
  QueueNode<E>* last_;  // The last node of the queue.
  size_t size_;  // The number of elements in the queue.

  // We disallow copying a queue.
  EventQueue(const EventQueue&);
  const EventQueue& operator = (const EventQueue&);
};
