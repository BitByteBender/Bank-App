#include "../headers/core.hpp"
#include "../headers/library/displayLib.hpp"
#include "../headers/library/inputLib.hpp"

void OnBeginPlay(void)
{
  uint16_t Num = 0;
  
  do {
    displayLib::MainMenuScreen("Main Menu Screen");
    Num = std::stoi(inputs::PromptReader("Choose from the list: "));
    if (Num >= 1 && Num <= 6)
      Functionalities(Num);
  } while (Num != 6);
}

void OnExit(void)
{
  exit(0);
}
