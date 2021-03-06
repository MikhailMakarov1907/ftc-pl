#pragma once

#include "../../../Vendor.hpp"

class FataEngine {

public:

    /**
     *
     * @function - GenerateProcessKey.
     * @point    - Generate "security" key for this application. (Engine used this key as xor/Based on ProcessId)
     *
     * @function - SearchOffsets.
     * @point    - Keep offsets up2date. [Legacy way]
     *
     * @function - DestroyChildProcess.
     * @point    - Destroy second application process. (Created for "Bypass security")
     *
     */

    void GenerateProcessKey (), SearchOffsets (), DestroyChildProcess ();

private:

    //Offset definition.
    struct Offset {

        //Signature for sigsearch.
        const char* m_signature;

        //RVA to buffer;
        int m_rva;

        //If offset native-oriented this value need to be false.
        bool m_isBufferOriented = false;

    };

    //Offsets data.
    std::map <const char*, std::vector <Offset>> m_offsets = {

            { "client", {

                //RankReveal.
                { "55 8B EC 51 A1 ? ? ? ? 85 C0", 0x2AD5F0 },

                //GetCheckSum.
                { "53 8B D9 83 C8", 0x2AD704 },

                //SetAbsAngles.
                { "55 8B EC 83 E4 F8 83 EC 5C 53 8B D9 56 57 83 7B", 0x2B1014, true }

            } }

    };

};    