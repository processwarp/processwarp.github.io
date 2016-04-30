
#include <processwarp.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mt.h"

void clear() {
  const char script[] =
      "global.context.clearRect("
      "0, 0,"
      "global.canvas.width,"
      "global.canvas.height);";

  pw_gui_script(script);
}

void draw(time_t uptime, int scale, int result) {
  const char script[] =
      "var d = (new Date()).getTime() / 100 - (%1$ld * 10);"
      "var r = 1 - (d >= 100 ? 100 : d) / 50;"
      "var bs = global.canvas.height < global.canvas.width ?"
      "    global.canvas.height / 24 :"
      "    global.canvas.width  / 24;"
      "var by = global.canvas.height - bs * 24;"
      "var bx = global.canvas.width / 2 - bs * 12;"
      ""
      "global.context.fillStyle = 'black';"
      "global.context.font = \"bold \" + 2 * bs + \"px 'sans-serif'\";"
      "global.context.textAlign = 'center';"
      "global.context.fillText('Sum from 0 to %2$d is %3$d .', bx + bs * 12, by + bs * 2);"
      ""
      "global.context.fillStyle = 'silver';"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * (9 - 6.2 * Math.cos(r)), by + bs * (12 - 6.2 * Math.sin(r)),"
      "    bs * 1.5, r - 0.5, Math.PI + r - 0.5, false);"
      "global.context.fill();"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * (9 - 6.2 * Math.cos(r)), by + bs * (12 - 6.2 * Math.sin(r)),"
      "    bs * 1.5, Math.PI + r + 0.5, r + 0.5, false);"
      "global.context.fill();"
      ""
      "global.context.beginPath();"
      "global.context.arc(bx + bs * (15 + 6.2 * Math.cos(r)), by + bs * (12 - 6.2 * Math.sin(r)),"
      "    bs * 1.5, - r + 0.5, Math.PI - r + 0.5, false);"
      "global.context.fill();"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * (15 + 6.2 * Math.cos(r)), by + bs * (12 - 6.2 * Math.sin(r)),"
      "    bs * 1.5, Math.PI - r - 0.5, - r - 0.5, false);"
      "global.context.fill();"
      "global.context.fillStyle = 'white';"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * (9 - 6.2 * Math.cos(r)), by + bs * (12 - 6.2 * Math.sin(r)),"
      "    bs * 0.7, 0, Math.PI * 2, false);"
      "global.context.fill();"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * (15 + 6.2 * Math.cos(r)), by + bs * (12 - 6.2 * Math.sin(r)),"
      "    bs * 0.7, 0, Math.PI * 2, false);"
      "global.context.fill();"
      "global.context.strokeStyle = 'darkgray';"
      "global.context.lineWidth = bs;"
      "global.context.setLineDash([bs / 2, 1]);"
      "global.context.beginPath();"
      "global.context.moveTo(bx + bs * 9, by + bs * 12);"
      "global.context.lineTo(bx + bs * (9 - 5 * Math.cos(r)), by + bs * (12 - 5 * Math.sin(r)));"
      "global.context.stroke();"
      "global.context.beginPath();"
      "global.context.moveTo(bx + bs * 15, by + bs * 12);"
      "global.context.lineTo(bx + bs * (15 + 5 * Math.cos(r)), by + bs * (12 - 5 * Math.sin(r)));"
      "global.context.stroke();"
      "global.context.fillStyle = 'crimson';"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * (9 - 5 * Math.cos(r)), by + bs * (12 - 5 * Math.sin(r)),"
      "    bs * 0.8, 0, Math.PI * 2, false);"
      "global.context.fill();"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * (15 + 5 * Math.cos(r)), by + bs * (12 - 5 * Math.sin(r)),"
      "    bs * 0.8, 0, Math.PI * 2, false);"
      "global.context.fill();"
      ""
      "global.context.fillStyle = 'silver';"
      "global.context.beginPath();"
      "global.context.fillRect(bx + bs * 8, by + bs * 3, bs * 8, bs * 6);"
      "global.context.beginPath();"
      "global.context.fillRect(bx + bs * 9, by + bs * 10, bs * 6, bs * 7);"
      "global.context.beginPath();"
      "global.context.fillRect(bx + bs * 10, by + bs * 17, bs * 1, bs * 6);"
      "global.context.beginPath();"
      "global.context.fillRect(bx + bs * 13, by + bs * 17, bs * 1, bs * 6);"
      "global.context.fillStyle = 'gray';"
      "global.context.beginPath();"
      "global.context.fillRect(bx + bs * 11, by + bs * 9, bs * 2, bs * 1);"
      "global.context.beginPath();"
      "global.context.fillRect(bx + bs * 8, by + bs * 23, bs * 3, bs * 1);"
      "global.context.beginPath();"
      "global.context.fillRect(bx + bs * 13, by + bs * 23, bs * 3, bs * 1);"
      "global.context.fillStyle = 'white';"
      "global.context.beginPath();"
      "global.context.fillRect(bx + bs * 9, by + bs * 7, bs * 6, bs * 1);"
      "global.context.fillStyle = 'black';"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * 9.5, by + bs * 5, bs, 0, Math.PI * 2, false);"
      "global.context.fill();"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * 14.5, by + bs * 5, bs, 0, Math.PI * 2, false);"
      "global.context.fill();"
      "global.context.fillStyle = 'crimson';"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * 9, by + bs * 12, bs, Math.PI * 0.5, Math.PI * 1.5, false);"
      "global.context.fill();"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * 15, by + bs * 12, bs, Math.PI * 0.5, Math.PI * 1.5, true);"
      "global.context.fill();"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * 10.5, by + bs * 17, bs * 0.5, Math.PI * 0, Math.PI * 1, false);"
      "global.context.fill();"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * 13.5, by + bs * 17, bs * 0.5, Math.PI * 0, Math.PI * 1, false);"
      "global.context.fill();"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * 10.5, by + bs * 20, bs * 0.5, Math.PI * 0, Math.PI * 2, false);"
      "global.context.fill();"
      "global.context.beginPath();"
      "global.context.arc(bx + bs * 13.5, by + bs * 20, bs * 0.5, Math.PI * 0, Math.PI * 2, false);"
      "global.context.fill();";
  pw_gui_script(script, uptime, scale, result);
}

// スレッド数
const int THREAD_NUM = 2;
// 計算が終わった最新時間
time_t last_uptime = 1;
// 最新計算結果
int last_scale  = 0;
int last_result = 0;

int calc(int scale) {
  int sum = 0;
  for (int i = 1; i <= scale; i ++) {
    sum += i;
  }
  return sum;
}

void* loop(void* vptr_args) {
  // スレッドがいつでもワープ可能であると明示
  pw_set_processwarp_param(PW_KEY_WARP_TIMING, PW_VAL_ON_ANYTIME);

  while (1) {
    int scale  = genrand_int32() % 9999;
    int result = calc(scale);

    last_uptime = time(NULL);
    last_scale  = scale;
    last_result = result;
  }
}

int main(void) {
  // スレッドがいつでもワープ可能であると明示
  pw_set_processwarp_param(PW_KEY_WARP_TIMING, PW_VAL_ON_ANYTIME);
  pthread_t thread[THREAD_NUM];

  // 乱数初期化
  init_genrand((unsigned)time(NULL));

  // 画面を表示
  pw_gui_create();

  // 計算スレッド作成
  for (int i = 0; i < THREAD_NUM; i++) {
    if (pthread_create(&thread[i], NULL, loop, NULL)) {
      return EXIT_FAILURE;
    }
  }

  time_t last_upclock = 0;
  time_t now_clock    = 0;
  while (1) {
    // 画面書き換えでバッファが溢れないようにwaitをかける
    while(now_clock == last_upclock) {
      now_clock = time(NULL);
    }
    last_upclock = now_clock;

    // 画面表示
    clear();
    draw(last_uptime, last_scale, last_result);
    pw_gui_flush();
  }

  return EXIT_SUCCESS;
}
