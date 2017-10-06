#pragma once

#include "IXAFilmingJobDispatch.h"

class XAFilmingJobDispatcher :
    public IXAFilmingJobDispatch
{
public:
    XAFilmingJobDispatcher();
    ~XAFilmingJobDispatcher();

    virtual void AddJob(XAFilmingJobBase* job);
    virtual void ContinueJobs(const vector<int>& IDs);
    virtual void DeleteJobs(const vector<int>& IDs);
    virtual void PauseJobs(const vector<int>& IDs);
    virtual void RestartJobs(const vector<int>& IDs);
    virtual void UrgentJobs(const vector<int>& IDs);
    virtual void PushJobsProgress();
};

