import time
import random
import pygame
import sys
from pygame.locals import *

# Pygame 초기화
pygame.init()

# 창 크기 및 엄지손가락 이미지 로드
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("UP&DOWN GAME")
thumb_up = pygame.image.load(r"C:\Users\OK\Desktop\현준\엄지척.PNG")  # 엄지손가락을 향해 치켜세우는 이미지
thumb_down = pygame.image.load(r"C:\Users\OK\Desktop\현준\엄지다운.PNG")  # 엄지손가락을 내리는 이미지
intro_image= pygame.image.load(r"C:\Users\OK\Desktop\현준\초기창 이미지.PNG")
intro_image = pygame.transform.scale(intro_image, (800, 600))
ingame_image= pygame.image.load(r"C:\Users\OK\Desktop\현준\물음표.PNG")
ingame_image = pygame.transform.scale(ingame_image, (800, 600))

# Pygame에서 사용할 폰트 설정
font_path = r"C:\Users\OK\Desktop\현준\NanumGothic.ttf"  # 나눔고딕 폰트의 경로를 지정해주세요
font = pygame.font.Font(font_path, 36)

def get_input():
    input_rect = pygame.Rect(300, 500, 400, 40)
    input_text = ""
    input_active = True

    while input_active:
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()

            if event.type == KEYDOWN:
                if event.key == K_RETURN:
                    input_active = False
                elif event.key == K_BACKSPACE:
                    input_text = input_text[:-1]
                else:
                    input_text += event.unicode

        screen.fill((255, 255, 255))
        text1 = font.render("Welcome! Enter Min and Max values.", True, (255, 255, 255))
        screen.blit(intro_image, (0, 0))
        screen.blit(text1, (120, 100))
        # 입력창 그리기
        pygame.draw.rect(screen, (0, 0, 0), input_rect, 2)
        text_surface = font.render(input_text, True, (0, 0, 0))
        width = max(200, text_surface.get_width() + 10)
        input_rect.w = width
        screen.blit(text_surface, (input_rect.x + 5, input_rect.y + 5))

        pygame.display.flip()

    return int(input_text)

# 초기값 설정
minnum, maxnum = 1, 100
ok = False
while not ok:
    try:
        minnum = get_input()
        maxnum = get_input()
        ok = minnum <= maxnum
        if not ok:
            print('The minimum value must be greater than the maximum value.Please enter again.')

    except ValueError:
        print('Please enter a valid value')
    
cleared = False
ans = random.randrange(minnum, maxnum + 1)
trial = 0

input_text = ""
input_rect = pygame.Rect(300, 500, 400, 40)
input_active = True

while not cleared:
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
        pygame.display.update()
    
        if event.type == KEYDOWN:
            if event.key == K_RETURN:
                try:
                    inp = int(input_text)
                    if inp == ans:
                        cleared = True                        
                    elif inp < ans:  # 입력한 숫자가 정답보다 작다면
                        if abs(inp - ans) <= 10:  # 차이가 10 이하라면
                            print('The number entered is slightly smaller (it is within the error range of 10)')  # 힌트를 출력합니다.
                        else:
                            print('The number entered is small')  # 힌트를 출력합니다.
                    elif inp > ans:  # 입력한 숫자가 정답보다 크다면
                        if abs(inp - ans) <= 10:  # 차이가 10 이하라면
                            print('The number entered is slightly larger (it is within the error range of 10)')  # 힌트를 출력합니다.
                        else:
                            print('The number entered is large')  # 힌트를 출력합니다.
                    input_text = ""
                    # 엔터를 치면 엄지손가락 이미지 출력
                    screen.blit(thumb_up, (250, 180)) if inp < ans else screen.blit(thumb_down, (250, 180))
                    pygame.display.flip()
                    time.sleep(1)  # 1초 동안 이미지 유지
                except ValueError:
                    print('Please enter a valid value')
            elif event.key == K_BACKSPACE:
                input_text = input_text[:-1]
            else:
                input_text += event.unicode
    
    screen.fill((0, 255, 255))
    text = font.render(f" Please enter a number between {minnum}, {maxnum}.", True, (0, 0, 0))
    screen.blit(ingame_image, (0, 0))
    screen.blit(text, (100, 80))

    # 입력창 그리기
    pygame.draw.rect(screen, (0, 0, 0), input_rect, 2)
    text_surface = font.render(input_text, True, (0, 0, 0))
    width = max(200, text_surface.get_width() + 10)
    input_rect.w = width
    screen.blit(text_surface, (input_rect.x + 5, input_rect.y + 5))
    
    pygame.display.flip()

print('Clear! Correct:', ans)
pygame.quit()
sys.exit()
