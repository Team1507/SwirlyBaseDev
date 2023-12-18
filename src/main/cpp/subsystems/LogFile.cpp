#include "Robot.h"
#include "subsystems/LogFile.h"
#include "subsystems/Drivetrain.h"


#include <ostream>
#include <fstream>
#include <cmath>
#include <string>
#include <ctime>
#include <iomanip>      // std::setprecision

using namespace std;

#define LOGFILEDIRNAME "/media/sda1/logs/"          //mounted USB Drive

//Static File handler
static std::ofstream logfile;


/*******************************
 ** LogFile
 *******************************/
LogFile::LogFile( void )
{
    cout<<"In LogFile" << endl;
}

/*******************************
 ** LogFilePeriodic
 *******************************/
void LogFile::LogFilePeriodic( void )
{
    if( !logfile.is_open() ) return;


    //Calculate delta time
    double curr_time = (double)frc::Timer::GetFPGATimestamp() - m_logStartTime;

    //Ptrs strictly for convienance
    // RobotContainer *rc = &robotcontainer;
    Drivetrain *drivetrain = &robotcontainer.m_drivetrain;


    logfile << std::fixed << std::setprecision(3);

    logfile << curr_time                         << ","; // 1:  ms since start
   
    //Odometry
    logfile << drivetrain->GetOdometryX()        << ","; // 2
    logfile << drivetrain->GetOdometryY()        << ","; // 3
    logfile << drivetrain->GetOdometryHeading()  << ","; // 4





    //Must be last
    logfile << "\n";
}



/*******************************
 ** LogFileEnable
 *******************************/
void LogFile::LogFileEnable( bool enable )
{
    if( enable ) LogfileOpen();
    else         LogfileClose();
}

/*******************************
 ** IsLogFileEnabled
 *******************************/
bool IsLogFileEnabled(void)
{
    return logfile.is_open();
}


/*******************************
 ** LogfileOpen (private)
 *******************************/
void LogFile::LogfileOpen(void)
{
    if( logfile.is_open() ) return;


    std::string filename;
    char tbuf[100];

    //Get current time and format into a filename -> mmdd_HHMMSS
    std::time_t time = std::time(0); 
    std::tm*    ts   = std::localtime(&time);
    strftime(tbuf, sizeof(tbuf), "%m%d_%H%M%S", ts);

    //Generate path and filename into a string
    filename  = LOGFILEDIRNAME;     //Start with directory
    filename += "log_";             //Add log prefix    
    filename += tbuf;               //Add time file name
    filename += ".csv";             //Add CSV as the extention

    //Finally, open the file
	logfile.open(filename, std::ios::out | std::ios::trunc );

	if( logfile.is_open() )
    {
        std::cout<<"LogFile Opened: " << tbuf <<std::endl;
        //Write header
        logfile << "Time"       << ","; // 1:  ms since start

        logfile << "X"          << ","; // 2:  X
        logfile << "Y"          << ","; // 3:  Y
        logfile << "Vel"        << ","; // 4:  Heading



        //Must be last
        logfile << "\n";
    }     
	else
        std::cout<<"*** Could NOT Open Logfile!!!!"<<std::endl;
		

    m_logStartTime = (double)frc::Timer::GetFPGATimestamp();

}
/*******************************
 ** LogfileClose (private)
 *******************************/
void LogFile::LogfileClose(void)
{
    if( !logfile.is_open() ) return;

    logfile.close();
    cout<<"LogFile Closed"<<endl;
}