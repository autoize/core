
#include "../CEpubFile.h"
#include "../../DesktopEditor/common/File.h"
#include "../../DesktopEditor/common/Directory.h"

#include <time.h>

int main(int argc, char *argv[])
{
    std::vector<std::wstring> arFiles = NSDirectory::GetFiles(NSFile::GetProcessDirectory() + L"/../../../Files");
    std::wstring sTmp = NSFile::GetProcessDirectory() + L"/tmp";
    std::wstring sOutputDirectory = NSFile::GetProcessDirectory() + L"/OutputFiles";
    NSDirectory::CreateDirectory(sOutputDirectory);

    clock_t tTime1 = clock();
    //Русские символы в консоль не выводятся
    for (std::wstring sFileName : arFiles)
    {
        clock_t tTimeBegin = clock();

        CEpubFile oEpub;

        if (oEpub.IsEbubFile(sFileName) == S_OK)
        {
            std::wstring sFile = sFileName.substr(0, sFileName.find_last_of(L'.'));

            auto posLastSlash = sFile.find_last_of(L'\\');

            if (posLastSlash != std::wstring::npos)
                sFile = sFile.substr(posLastSlash + 1);

            std::wcout << L"|----------|" << sFile << L"|----------|" << std::endl;

            oEpub.SetTempDirectory(sTmp);
            oEpub.Convert(sFileName, sOutputDirectory + L"/" + sFile + L".docx");
//            oEpub.ShowMap();
        }
        else
            std::wcout << sFileName << L" this is not an epub format!" << std::endl;
        clock_t tTimeEnd = clock();

        std::wcout << (double)(tTimeEnd - tTimeBegin) / CLOCKS_PER_SEC << std::endl;
    }

    clock_t tTime2 = clock();

    std::wcout << (double)(tTime2 - tTime1) / CLOCKS_PER_SEC << std::endl;

    return 0;
}