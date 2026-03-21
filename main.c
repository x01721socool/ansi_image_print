#include <stdlib.h>
#include <stdint.h>
#include "ansi_color.h"
#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include "stb_image.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize2.h"
#define STB

void	print_image(unsigned char *image, int x, int y, int channels)
{
	int size;

	size = x * y * channels;
	for (size_t i = 0; i < size; i += channels)
	{
		if (i / channels % x == 0)
			printf("\n");
		printf(ANSI_BACKGROUND_RGB("  ", %u, %u, %u), image[i], image[i + 1], image[i + 2]);
	}
	printf("\n");
}

int main(void)
{
	const char	filename[] = "landscape.jpg";
	//const char	filename[] = "42_logo-96.png";
	uint8_t	*image;
	uint8_t	*resized_image;
	int		x, y, n;
	int		rx, ry;

	image = stbi_load(filename, &x, &y, &n, 3);
	if (image == NULL)
	{
		printf(ANSI_COLOR("Error:", ANSI_RED)" %s\n", stbi_failure_reason());
		return (EXIT_FAILURE);
	}
	printf("post load\n");
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("n = %d\n", n);
	rx = 96;
	ry = 96;
	resized_image = malloc(3 * rx * ry);
	if (!stbir_resize_uint8_srgb(image, x, y, 0, resized_image, rx, ry, 0, STBIR_RGB))
		return (EXIT_FAILURE);
	printf("post resize\n");
	printf("image = %p\n", resized_image);
	print_image(resized_image, rx, ry, 3);
	stbi_image_free(image);
	stbi_image_free(resized_image);
	return (EXIT_SUCCESS);
}
