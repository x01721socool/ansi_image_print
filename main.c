#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include "ansi_color.h"
#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include "stb_image.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize2.h"

static bool	is_str_num(char *str)
{
	if (str == NULL)
		return (false);
	for (size_t i = 0; str[i] != '\0'; i++)
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

static char	*arguments_handler(int argc, char **argv)
{
	if (argc != 4 || !is_str_num(argv[2]) || !is_str_num(argv[3]))
	{
		printf(
			ANSI_COLOR("Invalid arguments.\nUsage:", ANSI_RED)" ./printimage "
			ANSI_COLOR("<filename> <width to display> ", ANSI_MAGENTA)
			ANSI_COLOR("<height to display>", ANSI_MAGENTA)"\n"
		);
		return (NULL);
	}
	return (argv[1]);
}

static bool	print_image(uint8_t *image, int x, int y, int channels)
{
	size_t size;

	size = x * y * channels;
	for (size_t i = 0; i < size; i += channels)
	{
		if (i / channels % x == 0)
			printf("\n");
		if (channels >= 3)
			printf(ANSI_BACKGROUND_RGB("  ", %u, %u, %u),
				   image[i], image[i + 1], image[i + 2]);
		else if (channels >= 1)
			printf(ANSI_BACKGROUND_RGB("  ", %u, %u, %u),
				   image[i], image[i], image[i]);
		else
			return (false);
	}
	printf("\n");
	return (true);
}

static bool	resize_and_print(uint8_t *image, int width, int height,
							 int resized_width, int resized_height, int channels)
{
	uint8_t	*resized_image;

	resized_image = malloc(channels * resized_width * resized_height);
	if (!stbir_resize_uint8_srgb(image, width, height, 0, resized_image,
								 resized_width, resized_height, 0, STBIR_RGB))
		return (false);
	print_image(resized_image, resized_width, resized_height, channels);
	stbi_image_free(resized_image);
	return (true);
}

int	main(int argc, char **argv)
{
	char	*filename;
	uint8_t	*image;
	int		width, height, expected_channels, channels;
	int		resized_width, resized_height;

	filename = arguments_handler(argc, argv);
	if (filename == NULL)
		return (EXIT_FAILURE);
	channels = 3;
	image = stbi_load(filename, &width, &height, &expected_channels, channels);
	if (image == NULL)
	{
		printf(ANSI_COLOR("Error:", ANSI_RED)" %s\n", stbi_failure_reason());
		return (EXIT_FAILURE);
	}
	resized_width = atoi(argv[2]);
	resized_height = atoi(argv[3]);
	if (resized_width == width && resized_height == height)
		print_image(image, width, height, channels);
	else if (!resize_and_print(image, width, height, resized_width, resized_height, channels))
	{
		printf(ANSI_COLOR("Error: failed to resize the image.", ANSI_RED)"\n");
		stbi_image_free(image);
		return (EXIT_FAILURE);
	}
	stbi_image_free(image);
	return (EXIT_SUCCESS);
}
