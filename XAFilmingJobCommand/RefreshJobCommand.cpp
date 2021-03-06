#include "RefreshJobCommand.h"
#include "XAFilmingLogger.h"

void RefreshJobCommand::Excute(const std::string& serializedParameters)
{
    LOG_INFO_XA_FILMING << "Refresh job command with serializedParameters [" << serializedParameters << "]" << LOG_END;
    _jobDispatcher->PushJobsProgress();
}
