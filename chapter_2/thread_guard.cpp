#include<thread>
#include<iostream>

class thread_guard
{
  std::thread& t;
public:
  explicit thread_guard(std::thread& t_):
    t(t_)
  {}

  ~thread_guard()
  {
    if (t.joinable())
    {
      t.join();
    }
  }
  thread_guard(thread_guard const&)=delete;
  thread_guard& operator=(thread_guard const&)=delete;
};


void run_thread() {
  // Below throws exeception due to not detching or joining
  //std::thread hello([](){std::cout << "hello" << std::endl;});

  std::thread hello([](){std::cout << "hello" << std::endl;});
  thread_guard hello_guard(hello);
}

int main() {
  run_thread();
}
