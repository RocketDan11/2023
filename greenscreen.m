clc;
clear all;
close all;

%choose foreground image
I = imread('front.jpeg');

imshow(I);
I(1,1,1) % red
I(1,1,2) % green
I(1,1,3) % blue

%choose background image
I2 = imread('back.jpeg');

figure();
imshow(I2);

[rows, cols, colors] = size(I)

for ii = 1:rows
     for jj = 1:cols

         if I(ii,jj,2) > 250
            I(ii,jj,1) = I2(ii,jj,1);
            I(ii,jj,2) = I2(ii,jj,2);
            I(ii,jj,3) = I2(ii,jj,3);
         end

     end
end

figure();
imshow(I);
