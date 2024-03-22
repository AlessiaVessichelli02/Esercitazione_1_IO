#include <iostream>
#include <fstream>
#include <iomanip>

double mappedValues(double val, int a, int b, int c, int d)
{
    double valmapped = d + (val-b)*(d-c)/(b-a);
    return valmapped;
}

double meanFunction(double sum, int num)
{
    double mean = sum/num;
    return mean;
}

int main()
{
    int a = 1;
    int b = 5;
    int c = -1;
    int d = 2;
    std::string datiInput = "data.csv";
    std::ifstream ifstr(datiInput);
    std::string fileResult = "result.csv";
    std::ofstream ofs(fileResult);

    if (ifstr.fail())
    {
        std::cerr << "File not exist" << std::endl;
        return 1;
    }

    double sum = 0;
    int i = 0;
    double val;
    ofs << "#N Mean" << std::endl;

    while(ifstr >> val)
    {
        double mvalue = mappedValues(val, a, b, c, d);
        sum += mvalue;
        i += 1;
        double mean = meanFunction(sum, i);
        ofs << i << " " << std::fixed << std::setprecision(16) << std::scientific << mean << std::endl;
    }
    ifstr.close();
    ofs.close();
    return 0;
}
