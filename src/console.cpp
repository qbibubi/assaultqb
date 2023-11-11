#include "../include/console.h"


void Console::init()
{
    AllocConsole();
    freopen_s(&this->m_dummy, "CONIN$", "r", stdin);
    freopen_s(&this->m_dummy, "CONOUT$", "w", stderr);
    freopen_s(&this->m_dummy, "CONOUT$", "w", stdout);

    this->isAttached = true;
}

void Console::exit()
{
    fclose(this->m_dummy);
    FreeConsole();

    this->isAttached = false;
}

void Console::printInfo()
{
    // pass entity there, this is just purely testing
    // print playerentity info
    std::cout << std::setw(15) << std::left << "You, an intelectual:\n";
    std::cout << std::setw(10) << std::left << "\tX: " << 2.137420 << '\n';
    std::cout << std::setw(10) << std::left << "\tY: " << 4.206900 << '\n';
    std::cout << std::setw(10) << std::left << "\tZ: " << -2.137690 << '\n';

    std::cout << "\n\n";
    std::cout << "Entities\n";
    // foreach entity in entity
    //  printRow of entity info

    std::cout << std::setw(10) << std::left << "\tEntity: ";
    std::cout << std::setw(40) << std::left << "Long_Ass_Entity_Name_Provided_By_Game_SA";
    std::cout << std::setw(8) << std::left << "X:" << 2.137420;
    std::cout << std::setw(8) << std::left << "Y:" << 2.137420;

}