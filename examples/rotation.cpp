#include "BitmapPlusPlus.hpp"
#include <iostream>

int main(void) {
    try {
        bmp::Bitmap image;

        // Load the original bitmap
        image.load("images/penguin.bmp");
        
        // Test vertical flip
        bmp::Bitmap flipped_v = image.flip_v();
        flipped_v.save("images/rotated/penguin_flipped_v.bmp");
        std::cout << "Vertical flip saved as penguin_flipped_v.bmp" << std::endl;

        // Test horizontal flip
        bmp::Bitmap flipped_h = image.flip_h();
        flipped_h.save("images/rotated/penguin_flipped_h.bmp");
        std::cout << "Horizontal flip saved as penguin_flipped_h.bmp" << std::endl;

        // Test rotate 90 degrees to the right
        bmp::Bitmap rotated_right = image.rotate_90_right();
        rotated_right.save("images/rotated/penguin_rotated_right.bmp");
        std::cout << "Rotated 90 degrees right saved as penguin_rotated_right.bmp" << std::endl;

        // Test rotate 90 degrees to the left
        bmp::Bitmap rotated_left = image.rotate_90_left();
        rotated_left.save("images/rotated/penguin_rotated_left.bmp");
        std::cout << "Rotated 90 degrees left saved as penguin_rotated_left.bmp" << std::endl;

        // You can also use the commands on the object itself and chain them together
        image.rotate_90_left_self().flip_h_self().rotate_90_right_self().flip_v_self().BGRToRGB().save("images/rotated/penguin_self.bmp");
        return EXIT_SUCCESS;
    }
    catch (const bmp::Exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}

