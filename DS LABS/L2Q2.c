#include <stdio.h>

struct Time {
    int hour;
    int min;
    int sec;
};

struct Time addTime(struct Time t1, struct Time t2) {
    struct Time result;
    int carry = 0;

    result.sec = t1.sec + t2.sec;
    if (result.sec >= 60) {
        result.sec -= 60;
        carry = 1;
    }

    result.min = t1.min + t2.min + carry;
    carry = 0;
    if (result.min >= 60) {
        result.min -= 60;
        carry = 1;
    }

    result.hour = t1.hour + t2.hour + carry;

    return result;
}

struct Time subtractTime(struct Time t1, struct Time t2) {
    struct Time result;
    int borrow = 0;

    result.sec = t1.sec - t2.sec;
    if (result.sec < 0) {
        result.sec += 60;
        borrow = 1;
    }

    result.min = t1.min - t2.min - borrow;
    borrow = 0;
    if (result.min < 0) {
        result.min += 60;
        borrow = 1;
    }

    result.hour = t1.hour - t2.hour - borrow;

    return result;
}

void readTime(struct Time *t) {
    printf("Enter hour, minute, and second (in HH:MM:SS format): ");
    scanf("%d:%d:%d", &t->hour, &t->min, &t->sec);
}

void displayTime(struct Time t) {
    printf("%02d:%02d:%02d\n", t.hour, t.min, t.sec);
}

int main7() {
    struct Time time1, time2, sum, difference;

    printf("Enter time 1:\n");
    readTime(&time1);

    printf("Enter time 2:\n");
    readTime(&time2);

    sum = addTime(time1, time2);
    printf("Sum of time1 and time2: ");
    displayTime(sum);

    difference = subtractTime(time1, time2);
    printf("Difference between time1 and time2: ");
    displayTime(difference);

    return 0;
}
