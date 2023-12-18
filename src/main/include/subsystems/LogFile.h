#ifndef LOGFILE_H
#define LOGFILE_H

class LogFile
{
    private:
        void   LogfileOpen(void);
        void   LogfileClose(void);
        double m_logStartTime;

    public:
        LogFile(void);

        void LogFileEnable( bool enable );
        void LogFilePeriodic( void );
        bool IsLogFileEnabled(void);

};

#endif //LOGFILE_H