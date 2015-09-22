#!/usr/bin/python3

class Tri:
    def __init__(self, width):
        self.width = width

    def get_area(self):
        print('[]' * self.width)

        if self.width <= 0:
            return 0

        if self.width == 1:
            return 1

        tri = Tri(self.width - 1)

        return tri.get_area() + self.width

if __name__ == '__main__':
    width = input('Enter width of triangle: ')
    tri = Tri(int(width))
    print(tri.get_area())
