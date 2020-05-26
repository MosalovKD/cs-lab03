#include "histogram.h"
#include "svg.h"
#include <iostream>


void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>\n";
}

void svg_rect(double x, double y, double width, double height, string stroke = "black", string fil = "black" )
{
    cout << "<rect x='" << x <<"' y='" << y << "' width='" << width << "' height='" << height << "' "
         << "stroke='" << stroke << "' fill='" << fil << "' />";
}

void hist_scale (int& HIST_WIDTH, double& BLOCK_WIDTH, const vector<size_t>& bins) // domashnee zadanie
{
    size_t kol_vo_chisel = 0;
    for (size_t bin : bins)
    {
        kol_vo_chisel = kol_vo_chisel + bin;
    }
    size_t binmax = find_maxinbins(bins);
    BLOCK_WIDTH = HIST_WIDTH/binmax;
    if (HIST_WIDTH < 1/3.0 * kol_vo_chisel * BLOCK_WIDTH)
    {
         HIST_WIDTH = 1/3.0 * kol_vo_chisel * BLOCK_WIDTH;
         cerr << endl << "error: shirina ochen' malen'kaya. Vvedite znachenie ot" <<
         HIST_WIDTH << "do 800.";
         exit(0);
    }
}

void svg_end()
{
    cout << "</svg>\n";
}

void show_histogram_svg(const vector<size_t>& bins, Input* p_input)
{
    int HIST_WIDTH = p_input->HIST_WIDTH;;
    double BLOCK_WIDTH; //(koeff)
    size_t binmax = find_maxinbins(bins);
    hist_scale(HIST_WIDTH, BLOCK_WIDTH, bins);
    const auto IMAGE_WIDTH = HIST_WIDTH + 50;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    for (size_t bin : bins)
    {
    double bin_width = BLOCK_WIDTH * bin;
    if (bin == binmax)
    {
        bin_width = HIST_WIDTH;
    }
    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
    svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "red", "#ffeeee");
    top += BIN_HEIGHT;
    }

    svg_end();
}
