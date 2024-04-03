#include <Logme/Logger.h>

#include "../CommandRegistrar.h"

using namespace Logme;

COMMAND_DESCRIPTOR2("list", Logger::CommandList);

bool Logger::CommandList(Logme::StringArray& arr, std::string& response)
{
  Guard guard(Instance->DataLock);

  for (auto& c : Instance->Channels)
    response += c.first + "\n";

  SortLines(response);
  return true;
}

