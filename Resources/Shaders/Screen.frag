#version 430 core

in vec2 fsTextureCoord;

uniform sampler2DMS screenTexture;
uniform int windowWidth;
uniform int windowHeight;
uniform int samples;

out vec4 outColor;

void main()
{
     // texelFetch requires a vec of ints for indexing (since we're indexing pixel locations).
    // fsTextureCoord is in range [0, 1], we need to map it to [0, windowWidth].

    ivec2 windowCoords = ivec2(windowWidth, windowHeight);
    windowCoords.x = int(windowCoords.x * 0.5 * fsTextureCoord.x - 1);
    windowCoords.y = int(windowCoords.y * 0.5 * fsTextureCoord.y - 1);
    //do a simple average since this is just a demo\n"
    vec4 sample1 = texelFetch(screenTexture, windowCoords, 0);
    vec4 sample2 = texelFetch(screenTexture, windowCoords, 1);
    vec4 sample3 = texelFetch(screenTexture, windowCoords, 2);
    vec4 sample4 = texelFetch(screenTexture, windowCoords, 3);

    outColor = vec4(sample1 + sample2 + sample3 + sample4) / 4.0f;
}
