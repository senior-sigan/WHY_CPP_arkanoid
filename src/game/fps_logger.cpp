#include "game/fps_logger.h"
#include <whycpp/palette.h>
#include <whycpp/text.h>
#include <whycpp/time.h>
#include <sstream>

void FpsLogger::Log(Context& ctx) {
  auto fps = GetFPS(ctx);
  std::stringstream ss;
  ss << "FPS=" << fps;
  Print(ctx, ss.str(), 10, 243, PALETTE[7]);
}
