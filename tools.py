# -*- coding: utf-8 -*-


def save_to_file(matrix):
    file = open("data.txt", 'w')
    for foo in matrix:
        for bar in foo:
            file.write("{} ".format(bar))
        file.write("\n")


def make_matrix(width, height):
    return [[0 for x in range(width)] for y in range(height)]
