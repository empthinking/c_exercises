#include "raylib.h"
#include <string.h>

typedef struct {
  Rectangle body;
  float speed;
  char score[2];
  struct {
    KeyboardKey up;
    KeyboardKey down;
  } control;
} Player;

typedef struct {
  Vector2 position;
  Vector2 speed;
  float radius;
  bool collision;
} Ball;

// Dimensões de tamanho
const float screenWidth = 800.0f;
const float screenHeight = 450.0f;
const float playerRecWidth = 10.0f;
const float playerRecHeight = 80.0f;
const float ballRadius = 10.0f;

// Constantes de posicao

const float screenCenterX = screenWidth / 2;
const float screenCenterY = screenHeight / 2;
const float screenTopLimit = 0.0f;
const float screenBottomLimit = screenHeight;
const float screenLeftLimit = 0.0f;
const float screenRightLimit = screenWidth;

// constantes de cinetica
const float playerSpeed = 5.0f;
const float ballSpeedY = 4.0f;
const float ballSpeedX = 5.0f;
const float ballAcceleration = 1.1f;

// Entidades
Player player1 = {{10, screenCenterY, playerRecWidth, playerRecHeight},
                  playerSpeed,
                  "0",
                  {KEY_W, KEY_S}};

Player player2 = {
    {screenWidth - 20, screenCenterY, playerRecWidth, playerRecHeight},
    playerSpeed,
    "0",
    {KEY_UP, KEY_DOWN}};

Ball ball = {
    {screenCenterX, screenCenterY}, {ballSpeedX, ballSpeedY}, ballRadius};

Rectangle line = {screenCenterX - 5, 10, 10, screenHeight - 20};

void DrawScores(char *, char *);
void gameover(void);
void resetBallStatus(Ball *);
void resetPlayerStatus(Player *);
void updateBallEntity(Ball *);
// void updatePlayerStatus(Player*);
void updatePlayerPosition(Player *p);

int main(void) {
  InitWindow(screenWidth, screenHeight, "Pong Game");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    // Movimentos jogador 1
    updatePlayerPosition(&player1);

    // Movimentos jogador 2
    updatePlayerPosition(&player2);

    // Colisao esfera
    // Teto e piso
    if (ball.position.y - ball.radius <= screenTopLimit ||
        ball.position.y + ball.radius >= screenBottomLimit) {
      ball.speed.y *= -1.0f;
    }
    // Colisao jogador 1
    if ((ball.position.y + ball.radius) > player1.body.y &&
        (ball.position.y - ball.radius) <
            (player1.body.y + player1.body.height)) {
      if ((ball.position.x - ballRadius <=
           player1.body.x + player1.body.width) &&
          ball.collision == false) {
        // limitador de aceleracao
        ball.speed.x *= ball.speed.x >= -20.0f ? -ballAcceleration : -1;
        ball.collision = true;
      }
    }
    // Colisao jogador 2
    if ((ball.position.y + ball.radius) > player2.body.y &&
        (ball.position.y - ball.radius) <
            (player2.body.y + player2.body.height)) {
      if ((ball.position.x + ballRadius >= player2.body.x) &&
          ball.collision == false) {
        // limitador de aceleracao
        ball.speed.x *= ball.speed.x <= 20.0f ? -ballAcceleration : -1;
        ball.collision = true;
      }
    }

    // Area de mudanca no estado de colisao
    if (ball.position.x > screenLeftLimit + 50 &&
        ball.position.x < screenRightLimit - 50) {
      ball.collision = false;
    }

    // Ponto jogador 1
    if (ball.position.x + ballRadius >= screenRightLimit) {
      if (++player1.score[0] < '7') {
        resetBallStatus(&ball);
      } else {
        gameover();
      }
    }
    // Ponto jogador 2
    else if (ball.position.x + ballRadius <= 0) {
      if (++player2.score[0] < '7') {
        resetBallStatus(&ball);
      } else {
        gameover();
      }
    }
    ball.position.x += ball.speed.x;
    ball.position.y += ball.speed.y;

    BeginDrawing();
    ClearBackground(BLACK);
    DrawScores(player1.score, player2.score);
    DrawRectangleRec(player1.body, WHITE);
    DrawRectangleRec(player2.body, WHITE);
    DrawRectangleRec(line, GRAY);
    DrawCircleV(ball.position, ball.radius, WHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

void gameover(void) {
  while (true) {
    if (IsKeyPressed(KEY_R)) {
      resetBallStatus(&ball);
      resetPlayerStatus(&player1);
      resetPlayerStatus(&player2);
      break;
    }
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Game Over (Pressione 'R' para recomecar)", 190, 200, 20,
             LIGHTGRAY);
    EndDrawing();
  }
}

void DrawScores(char *player1, char *player2) {
  DrawText(player1, screenCenterX - 250, screenCenterY - 200, 100, RED);
  DrawText(player2, screenCenterX + 200, screenCenterY - 200, 100, BLUE);
}
void resetBallStatus(Ball *b) {
  b->position.x = screenCenterX;
  b->position.y = screenCenterY;
  b->speed.x = ballSpeedX;
  b->speed.y = ballSpeedY;
  b->collision = false;
}

void resetPlayerStatus(Player *p) {
  //   p->body.x = screenCenterX;
  //   p->body.y = screenCenterY;
  p->score[0] = '0';
}

void updatePlayerPosition(Player *p) {
  if (IsKeyDown(p->control.up) && p->body.y >= screenTopLimit)
    p->body.y -= p->speed;
  if (IsKeyDown(p->control.down) &&
      p->body.y <= screenBottomLimit - p->body.height)
    p->body.y += p->speed;
}
