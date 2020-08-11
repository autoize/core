#include "CDocumentStyle.h"

#include <iostream>

namespace NSCSS
{
    CDocumentStyle::CDocumentStyle()
    {
    }

    CDocumentStyle::~CDocumentStyle()
    {
    }

    std::wstring CDocumentStyle::GetStyle()
    {
        return m_sStyle;
    }

    std::wstring CDocumentStyle::GetId()
    {
        return m_sId;
    }

    void CDocumentStyle::WriteStyle(NSCSS::CCompiledStyle &oStyle)
    {
        m_sId = oStyle.GetId();
        // пофиксить появление пробелов
        std::wstring sId = m_sId;
        if (sId.find(L" ") != std::wstring::npos)
            sId = sId.substr(0, sId.find(L" "));

        m_sStyle = L"<w:style w:type=\"paragraph\" w:customStyle=\"1\" w:styleId=\"" + sId + L"\">";

        m_sStyle += L"<w:name w:val=\"" + sId + L"\"/>";
        m_sStyle += L"<w:qFormat/>";

        std::wstring sPPr = L"<w:pPr>";
        std::wstring sRPr = L"<w:rPr>";

        if (!oStyle.GetColor().empty())
            sRPr += L"<w:color w:val=\"" + oStyle.GetColor() + L"\"/>";

        if (!oStyle.GetFontSize().empty())
        {
            std::wstring sFontSize = oStyle.GetFontSize();
            if (isdigit(sFontSize[0]))
            {
                sRPr += L"<w:sz w:val=\"" + sFontSize + L"\"/>";
            }
        }
        if (!oStyle.GetFontFamily().empty())
        {
            std::wstring sFontFamily = oStyle.GetFontFamily();
            sRPr += L"<w:rFonts w:ascii=\"" + sFontFamily + L"\" w:hAnsi=\"" + sFontFamily + L"\"/>";
        }

        if (!oStyle.GetTextAlign().empty())
        {
            std::wstring sTextAlign = oStyle.GetTextAlign();
            if (sTextAlign != L"justify")
                sPPr += L"<w:jc w:val=\"" + oStyle.GetTextAlign() + L"\"/>";
            else if (sTextAlign == L"justify")
                sPPr += L"<w:jc w:val=\"both\"/>";
        }
        if (!oStyle.GetFontStyle().empty())
        {
            std::wstring sFontStyle = oStyle.GetFontStyle();
            if (sFontStyle == L"italic")
                sRPr += L"<w:i w:val=\"true\"/>";
        }

        if (!oStyle.GetFontWeight().empty())
        {
            std::wstring sFontWeight = oStyle.GetFontWeight();
            if (sFontWeight == L"bold")
                sRPr += L"<w:b w:val=\"true\"/>";
        }

        if (!oStyle.GetTextIndent().empty())
            sPPr += L"<w:ind w:firstLine=\"" + oStyle.GetTextIndent() + L"\"/>";

//        if (!oStyle.GetPadding().empty())
//        {
//            std::wstring sInd = L"<w:ind ";
//            std::wstring sPaddingLeft = oStyle.GetPaddingLeft();
//            std::wstring sPaddingRight = oStyle.GetPaddingRight();
//            bool bFl = false;


//            if (sPaddingLeft != L"0")
//            {
//                bFl = true;
//                sInd += L"w:left=\"" + sPaddingLeft + L"\" ";
//            }
//            if (sPaddingRight != L"0")
//            {
//                bFl = true;
//                sInd += L"w:right=\"" + sPaddingRight + L"\"";
//            }
//            sInd += L"/>";

//            if (bFl)
//                m_sStyle += sInd;
//        }

//        if (true)
//        {
//            std::wstring sSpacing = L"<w:spacing ";
//            std::wstring sBefore = oStyle.GetMarginTop();
//            std::wstring sAfter = oStyle.GetMarginBottom();
//            std::wstring sLineHeight = oStyle.GetLineHeight();

//            if (isdigit(sBefore[0]))
//                sSpacing += L"w:before=\"" + sBefore + L"\" ";

//            if (isdigit(sAfter[0]))
//                sSpacing += L"w:after=\"" + sAfter + L"\" ";

//            if (isdigit(sLineHeight[0]))
//                sSpacing += L"w:line=\"" + sAfter + L"\" ";

//            sSpacing += L"w:lineRule=\"auto\"/>";

//            m_sStyle += sSpacing;
//        }

//        if (!oStyle.GetTextDecoration().empty())
//        {
//            std::wstring sTextDecoration = oStyle.GetTextDecoration();
//            if (sTextDecoration == L"underline")
//                m_sStyle += L"<w:u w:val=\"single\"/>";
//        }

//        if (!oStyle.GetBackgroundColor().empty())
//            m_sStyle += L"<w:background w:color=\"" + oStyle.GetBackgroundColor() + L"\"/>";

        sPPr += L"</w:pPr>";
        sRPr += L"</w:rPr>";
        m_sStyle += sPPr + sRPr + L"</w:style>";
    }
}
