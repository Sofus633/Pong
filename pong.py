import pygame


class Ball:
    def __init__(self, pos):
        self.position = pos
        self.radius = 10
        self.dirrection = [.04, .04]
    def update(self):
        self.position[0] += self.dirrection[0]
        self.position[1] += self.dirrection[1]
        
    def checkcollitions(self):
        global Running
        if self.position[0] > 800 or self.position[0] < 0:
            Running = False
        if self.position[1] < 0 or self.position[1] > 500 :
            self.dirrection[1] = - self.dirrection[1]
            
    def check_collisions(self, pad):
        ball_rect = pygame.Rect(self.position[0] - self.radius, self.position[1] - self.radius, self.radius * 2, self.radius * 2)
        pad_rect = pygame.Rect(pad.position[0], pad.position[1], pad.width, pad.height)

        if ball_rect.colliderect(pad_rect):
            self.dirrection[0] = -self.dirrection[0]

        if self.position[0] > 800 or self.position[0] < 0:
            Running = False
        if self.position[1] < 0 or self.position[1] > 500:
            self.dirrection[1] = -self.dirrection[1]
        
        
        
class Pad:
    def __init__(self, position):
        self.position = position
        self.width = 10
        self.height = 100
    def move(self, dirrection):
        if dirrection == 'up':
            self.position[1] -= 10
        else:
            self.position[1] += 10
            
pygame.init()    
screen = pygame.display.set_mode((800, 500)) 
Running = True 
pad1 = Pad([0, 40])
pad2 = Pad([800 - 10, 40])
ball = Ball([800/2, 500/2 ])
          
all = [pad1, pad2, ball]
          
def displayall():
    for elem in all:
        if type(elem) == Ball:
            pygame.draw.circle(screen, (100, 100, 100), elem.position, elem.radius)
        else: 
            rect = pygame.Rect(elem.position[0], elem.position[1], 10, 100)
            pygame.draw.rect(screen, (100, 100, 100), rect)
    

def main():
    
    while Running:
        for event in pygame.event.get():
            keys = pygame.key.get_pressed()

            if keys[pygame.K_z]:
                pad1.move("up")
            if keys[pygame.K_s]:
                pad1.move("down")
            if keys[pygame.K_o]:
                pad2.move("up")
            if keys[pygame.K_l]:
                pad2.move("down")
        displayall()
        ball.update()
        ball.check_collisions(pad1)
        ball.check_collisions(pad2)
        ball.checkcollitions()
        pygame.display.flip()
        screen.fill(0)


main()