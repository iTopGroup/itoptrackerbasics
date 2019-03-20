#include "classes/utility.h"

using namespace std;

Utility::Utility()
{
    //videos supported extensions
    VIDEXT.push_back("3G2");
    VIDEXT.push_back("3GP");
    VIDEXT.push_back("AVI");
    VIDEXT.push_back("MP4");
    VIDEXT.push_back("M1V");
    VIDEXT.push_back("M2V");
    VIDEXT.push_back("M4V");
    VIDEXT.push_back("MKV");
    VIDEXT.push_back("MOV");
    VIDEXT.push_back("MPEG1");
    VIDEXT.push_back("MPEG2");
    VIDEXT.push_back("MPEG4");
    VIDEXT.push_back("MPG");
    VIDEXT.push_back("VOB");
    VIDEXT.push_back("WMV");

    //pictures supported extensions
    PICEXT.push_back("BMP");
    PICEXT.push_back("TIFF");
    PICEXT.push_back("JPEG");
    PICEXT.push_back("GIF");
    PICEXT.push_back("PNG");
    PICEXT.push_back("JPG");
}

string Utility::getext(string path)
{
 int pos = path.rfind('.');

    string ext = path.substr(pos+1);
    int i = 0;
    char c;
    string result;
    while(ext[i])
    {
        c = ext[i];
        result += toupper(c);
        i++;
    }
    return result;
}

bool Utility::ispic(string path)
{
    string ext = getext(path);

    if(find(PICEXT.begin(), PICEXT.end(), ext) != PICEXT.end())
        return true;
    else
        return false;
}

bool Utility::isvideo(string path)
{
    string ext = getext(path);

    if(find(VIDEXT.begin(), VIDEXT.end(), ext) != VIDEXT.end())
        return true;
    else
        return false;
}
