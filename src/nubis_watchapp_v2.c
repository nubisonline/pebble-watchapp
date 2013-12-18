//Author: Tim van Dalen
//Though I pretty much just took the v2 watchapp example
#include "pebble.h"

static Window *window;

static BitmapLayer *image_layer;

static GBitmap *image;

int main(void) {
	window = window_create();
	window_stack_push(window, true);

	Layer *window_layer = window_get_root_layer(window);
	GRect bounds = layer_get_frame(window_layer);

	//Load in logo
	image = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_LOGO);

	//Draw the logo
	image_layer = bitmap_layer_create(bounds);
	bitmap_layer_set_bitmap(image_layer, image);
	bitmap_layer_set_alignment(image_layer, GAlignCenter);
	layer_add_child(window_layer, bitmap_layer_get_layer(image_layer));

	//Start main loop
	app_event_loop();

	//Unload the logo
	gbitmap_destroy(image);

	//Destroy the graphics layer
	bitmap_layer_destroy(image_layer);
	window_destroy(window);
}
