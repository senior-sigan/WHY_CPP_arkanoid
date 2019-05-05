#include "game/fps_logger.h"
#include <whycpp/palette.h>
#include <whycpp/text.h>
#include <whycpp/time.h>
#include <sstream>

void FpsLogger::Log(Context& ctx) {
  sum += GetDelta(ctx);
  i++;
  if (sum >= timer) {
    auto avg_dt = sum / i;
    fps = int(1.0 / avg_dt);
    // TODO: print somehow on the screen
    //    LOG_INFO("FPS: %d", fps);
    i = 0;
    sum -= timer;
  }
  std::stringstream ss;
  ss << "FPS=" << fps;

  Print(ctx, ss.str(), 10, 243, PALETTE[7]);
}
