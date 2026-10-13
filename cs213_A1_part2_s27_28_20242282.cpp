
#include <iostream>
#include <string>
#include "Image_Class.h"
#include <algorithm>
using namespace std;

class InvertFilter {
public:
    void apply(Image& img) {
        for (int x = 0; x < img.width; ++x)
            for (int y = 0; y < img.height; ++y)
                for (int c = 0; c < 3; ++c)
                    img(x, y, c) = 255 - img(x, y, c);
    }
};

class FrameFilter {
public:
    void apply(Image& img) {
        int t = 20;
        unsigned char R = 0, G = 0, B = 0;

        int lim = min(img.width, img.height) / 2;
        if (t > lim)
            t = lim;

        for (int y = 0; y < t; ++y) {
            for (int x = 0; x < img.width; ++x) {
                img(x, y, 0) = R;
                img(x, y, 1) = G;
                img(x, y, 2) = B;

                img(x, img.height - 1 - y, 0) = R;
                img(x, img.height - 1 - y, 1) = G;
                img(x, img.height - 1 - y, 2) = B;
            }
        }

        for (int y = 0; y < img.height; ++y) {
            for (int x = 0; x < t; ++x) {
                img(x, y, 0) = R;
                img(x, y, 1) = G;
                img(x, y, 2) = B;

                img(img.width - 1 - x, y, 0) = R;
                img(img.width - 1 - x, y, 1) = G;
                img(img.width - 1 - x, y, 2) = B;
            }
        }
    }
};

int main() {
    string filename;
    int choice;
    Image img;

    cout << "Enter image: ";
    cin >> filename;

    if (!img.loadNewImage(filename)) {
        cout << "Error loading image\n";
        return 0;
    }

    bool running = true;

    while (running) {
        cout << "\n--- Menu ---\n";
        cout << "0- Load new image\n";
        cout << "1- Gray\n";
        cout << "2- B&W\n";
        cout << "3- Invert\n";
        cout << "4- Frame\n";
        cout << "5- Flip\n";
        cout << "6- Save\n";
        cout << "7- Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Enter new image name: ";
            cin >> filename;

            if (!img.loadNewImage(filename))
                cout << "Error loading image\n";
            else
                cout << "New image loaded successfully!\n";
        }

        else if (choice == 1) {
            for (int y = 0; y < img.height; y++) {
                for (int x = 0; x < img.width; x++) {
                    int r = img(x, y, 0);
                    int g = img(x, y, 1);
                    int b = img(x, y, 2);

                    int gray = (r + g + b) / 3;

                    img(x, y, 0) = gray;
                    img(x, y, 1) = gray;
                    img(x, y, 2) = gray;
                }
            }

            cout << "Gray done\n";
        }

        else if (choice == 2) {
            for (int y = 0; y < img.height; y++) {
                for (int x = 0; x < img.width; x++) {
                    unsigned char R = img(x, y, 0);
                    unsigned char G = img(x, y, 1);
                    unsigned char B = img(x, y, 2);

                    unsigned char gray =
                        0.3 * R + 0.59 * G + 0.11 * B;

                    unsigned char bw = (gray > 128) ? 255 : 0;

                    img(x, y, 0) = bw;
                    img(x, y, 1) = bw;
                    img(x, y, 2) = bw;
                }
            }

            cout << "B&W done\n";
        }

        else if (choice == 3) {
            InvertFilter f;
            f.apply(img);

            cout << "Invert done\n";
        }

        else if (choice == 4) {
            FrameFilter f;
            f.apply(img);

            cout << "Frame done\n";
        }

        else if (choice == 5) {
            int f;

            cout << "1- H flip  2- V flip: ";
            cin >> f;

            if (f == 1) {
                for (int y = 0; y < img.height; y++) {
                    for (int x = 0; x < img.width / 2; x++) {
                        for (int c = 0; c < img.channels; c++) {
                            unsigned char t = img(x, y, c);

                            img(x, y, c) =
                                img(img.width - 1 - x, y, c);

                            img(img.width - 1 - x, y, c) = t;
                        }
                    }
                }
            }

            else if (f == 2) {
                for (int y = 0; y < img.height / 2; y++) {
                    for (int x = 0; x < img.width; x++) {
                        for (int c = 0; c < img.channels; c++) {
                            unsigned char t = img(x, y, c);

                            img(x, y, c) =
                                img(x, img.height - 1 - y, c);

                            img(x, img.height - 1 - y, c) = t;
                        }
                    }
                }
            }

            else {
                cout << "Invalid flip choice\n";
                continue;
            }

            cout << "Flip done\n";
        }

        else if (choice == 6) {
            string saveName;

            cout << "Enter file name to save current image: ";
            cin >> saveName;

            img.saveImage(saveName);

            cout << "Image saved successfully!\n";
        }

        else if (choice == 7) {
            cout << "Exit program.\n";
            running = false;
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

