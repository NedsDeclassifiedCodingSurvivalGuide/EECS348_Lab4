/*
Name: Sean Crosby
KU ID: 3117633
Date: 10/6/24
Class: EECS 348
Purpouse: Takes in a teperature and converts and categorizes it
*/

#include <stdio.h>

/* Fahrenheight conversions */
float fahrenheight_to_celcius(float input_value) {return ((input_value-32.0)*(5.0/9.0));}
float fahrenheight_to_kelvin(float input_value) {return (((input_value-32.0)*(5.0/9.0)) + 273.15);}

/* Ceclius conversions */
float celcius_to_fahrenheight(float input_value) {return (((9.0/5.0)*input_value) + 32.0);}
float celcius_to_kelvin(float input_value) {return (input_value + 273.15);}

/* Kelvin conversions */
float kelvin_to_fahrenheight(float input_value) {return (((input_value - 273.15)*(9.0/5.0)) + 32.0);}
float kelvin_to_celcius(float input_value) {return (input_value - 273.15);}


/* Converts the temp to celcius and categorizes it based on the range of temperature */
void categorize_temp(float temp, char scale) {
    if (scale == 'F') {temp = fahrenheight_to_celcius(temp);}
    else if (scale == 'K') {temp = kelvin_to_celcius(temp);}

    if (temp < 0.0) {printf("Category: Freezing\nIt's freezing out, bundle up!\n");}
    else if (temp < 10.0) {printf("Category: Cold\nIt's cold out, wear a jacket!\n");}
    else if (temp < 25.0) {printf("Category: Comfortable\nIt's nice out, throw on some shorts!\n");}
    else if (temp < 35.0) {printf("Category: Hot\nIt's hot out, make sure you hydrate!\n");}
    else {printf("Category: Extreme heat\nThere's extreme heat right now, stay indoors as much as possible!\n");}
}

int main(void) {
    /* Declarations */
    float input_temp;
    float output_temp;
    char input_type;
    char conversion_type;

    /* Assignments */
    printf("Input a temperature value and type (separated by a space): ");
    scanf("%f %c", &input_temp, &input_type);
    printf("What do you want to convert to? (F,C, or K): ");
    scanf(" %c", &conversion_type);

    /* Checks input and output types and calls the corresponding conversion function*/
    if (input_type == 'F') {
        if (conversion_type == 'F') {printf("Already in F!");}
        else if (conversion_type == 'C') {output_temp = fahrenheight_to_celcius(input_temp);}
        else if (conversion_type == 'K') {output_temp = fahrenheight_to_kelvin(input_temp);}
    }

    else if (input_type == 'C') {
        if (conversion_type == 'F') {output_temp = celcius_to_fahrenheight(input_temp);}
        else if (conversion_type == 'C') {printf("Already in C!");}
        else if (conversion_type == 'K') {output_temp = celcius_to_kelvin(input_temp);}
    }

    else if (input_type == 'K') {
        if (conversion_type == 'F') {output_temp = kelvin_to_fahrenheight(input_temp);}
        else if (conversion_type == 'C') {output_temp = kelvin_to_celcius(input_temp);}
        else if (conversion_type == 'K') {printf("Already in K!");}
    }

    else {printf("Invalid input!\n");}

    printf("Converted Temp: %f %c\n", output_temp, conversion_type);
    categorize_temp(input_temp,input_type);

    return 0;
}