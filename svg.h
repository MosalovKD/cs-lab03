#pragma once
#include "histogram.h"
#include <string>
void svg_begin(double width, double height);

void svg_text(double left, double baseline, string text);

void svg_rect(double x, double y, double width, double height);

void hist_scale (int& HIST_WIDTH, double& BLOCK_WIDTH, const vector<size_t>& bins); // domashnee zadanie

void svg_end();

void show_histogram_svg(const vector<size_t>& bins);


