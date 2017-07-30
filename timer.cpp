#include "Poco/Timer.h"
#include "Poco/Thread.h"
#include "Poco/Stopwatch.h"

#include <iostream>

using Poco::Timer;
using Poco::TimerCallback;
using Poco::Thread;
using Poco::Stopwatch;

class TimerExample {
private:

  Stopwatch sw;

public:

  TimerExample() {
    sw.start();
  }

  void onTimer(Timer& timer) {
    std::cout
      << "Callback called after "
      << sw.elapsed() / 1000
      << " milliseconds. " << std::endl;
  }
};

int main(int argc, char const *argv[]) {
  TimerExample example;
  Timer timer(250, 500);

  timer.start(TimerCallback<TimerExample>(example, &TimerExample::onTimer));

  Thread::sleep(5000);

  timer.stop();

  return 0;
}
