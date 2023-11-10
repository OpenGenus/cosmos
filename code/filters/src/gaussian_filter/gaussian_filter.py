##Author - Sagar Vakkala (@codezoned)


from PIL import Image
import numpy


def main():
    ##Load the Image (Change source.jpg with your image)
    image = Image.open("source.jpg")
    ##Get the width and height
    width, height = image.size
    ##Initialise a null matrix
    pix = numpy.zeros(shape=(width, height, 3), dtype=numpy.uint8)
    ##Same again
    matris = numpy.zeros(shape=(width, height, 3), dtype=numpy.uint8)
    # Neighbor matrice to be filtered pixel
    neighbour_matrice = numpy.zeros(shape=(5, 5))
    for i in range(width):
        for j in range(height):
            # Get and assign image's RGB values
            rgb_im = image.convert("RGB")
            r, g, b = rgb_im.getpixel((i, j))
            pix[i][j] = r, g, b
            if i >= 2 & i < (width - 2) & j >= 2 & j < (height - 2):
                for m in range(3):
                    toplam = 0.0
                    for k in range(5):
                        for l in range(5):
                            neighbour_matrice[k][l] = matris[k + i - 2][l + j - 2][
                                m
                            ]  # Create neighbor matrice's indexs(exclude a frame size=2)
                    for k in range(5):
                        for l in range(5):
                            toplam = toplam + (
                                neighbour_matrice[k][l] * 0.04
                            )  # 0.04 is filter value.
                    matris[j][i][m] = int(toplam)
    # Create an image with RGB values
    img = Image.fromarray(matris, "RGB")
    ##Save and show the image
    img.save("target.jpg")
    img.show()


if __name__ == "__main__":
    main()
