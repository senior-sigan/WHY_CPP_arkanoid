#ifndef GAME_SRC_GAME_FPS_LOGGER_H_
#define GAME_SRC_GAME_FPS_LOGGER_H_

class Context;

class FpsLogger {
  const int timer = 1;  // print each 1 second
  double sum = 0;
  int i = 0;
  int fps = 0;

 public:
  void Log(Context& ctx);
};

#endif //GAME_SRC_GAME_FPS_LOGGER_H_
