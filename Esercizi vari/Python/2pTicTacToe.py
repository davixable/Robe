import pygame
import random

pygame.init()

WIDTH, HEIGHT = 500, 500
CELL_SIZE = WIDTH // 3
SCREEN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Tic Tac Toe")

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
ORANGE = (255, 128, 0)
GREEN = (0, 204, 0)
RED = (160, 0, 0)

font = pygame.font.Font(None, 120)

board = [[None for _ in range(3)] for _ in range(3)]
current_player = 'X' if random.randint(0, 1) == 0 else 'O'
game_state = "PLAY"
winner = None

LINE_WIDTH = 7


def drawGrid():
    SCREEN.fill(BLACK)
    pygame.draw.line(SCREEN, WHITE, (15, HEIGHT // 3), (WIDTH - 15, HEIGHT // 3), LINE_WIDTH)
    pygame.draw.line(SCREEN, WHITE, (15, 2 * HEIGHT // 3), (WIDTH - 15, 2 * HEIGHT // 3), LINE_WIDTH)
    pygame.draw.line(SCREEN, WHITE, (WIDTH // 3, 15), (WIDTH // 3, HEIGHT - 15), LINE_WIDTH)
    pygame.draw.line(SCREEN, WHITE, (2 * WIDTH // 3, 15), (2 * WIDTH // 3, HEIGHT - 15), LINE_WIDTH)


def handleClick(pos):
    global current_player, game_state, winner

    if game_state == "END":
        return

    row = pos[1] // CELL_SIZE
    col = pos[0] // CELL_SIZE

    if board[row][col] is None:
        board[row][col] = current_player
        winner = checkWinner()

        if winner:
            game_state = "END"
        else:
            current_player = 'O' if current_player == 'X' else 'X'
            


def drawXO():
    for row in range(3):
        for col in range(3):
            if board[row][col] == 'X':
                drawX(row, col)
            elif board[row][col] == 'O':
                drawO(row, col)


def drawX(row, col):
    x_start = col * CELL_SIZE + 20
    y_start = row * CELL_SIZE + 20
    x_end = (col + 1) * CELL_SIZE - 20
    y_end = (row + 1) * CELL_SIZE - 20
    pygame.draw.line(SCREEN, RED, (x_start, y_start), (x_end, y_end), 5)
    pygame.draw.line(SCREEN, RED, (x_start, y_end), (x_end, y_start), 5)


def drawO(row, col):
    pygame.draw.circle(SCREEN, ORANGE, (col * CELL_SIZE + CELL_SIZE // 2, row * CELL_SIZE + CELL_SIZE // 2),
                       CELL_SIZE // 2.5, LINE_WIDTH)


def reset():
    global board, current_player, game_state, winner
    current_player = 'X' if random.randint(0, 1) == 0 else 'O'
    board = [[None for _ in range(3)] for _ in range(3)]
    winner = None
    game_state = "PLAY"


def checkWinner():
    for row in range(3):
        if board[row][0] == board[row][1] == board[row][2] and board[row][0] != None:
            return board[row][0]

    for col in range(3):
        if board[0][col] == board[1][col] == board[2][col] and board[0][col] != None:
            return board[0][col]

    if board[0][0] == board[1][1] == board[2][2] and board[0][0] != None:
        return board[0][0]

    if board[0][2] == board[1][1] == board[2][0] and board[0][2] != None:
        return board[0][2]

    return None


def drawWinner():
    if winner:
        text = font.render(f"{winner} ha vinto!", True, GREEN)
        text_rect = text.get_rect(center=(WIDTH // 2, HEIGHT // 2))
        SCREEN.blit(text, text_rect)


running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_r:
                reset()
        if event.type == pygame.MOUSEBUTTONDOWN:
            handleClick(event.pos)

    drawGrid()
    drawXO()
    drawWinner()
    pygame.display.update()

pygame.quit()
