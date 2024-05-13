#pragma once
struct comp {
	int Data;
	comp* next;
};

void push(comp** top, int D);
bool pop(comp** top);
void find(comp* top, int N);
void print(comp* top);
void toFile(comp* top);
void fromFile(comp** top);
void clear(comp** top);
void printFirstPositiveElement(comp** top);
