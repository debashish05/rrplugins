#pragma hdrstop
#include <iostream>
#include "telPluginManager.h"
#include "rr/rrException.h"
#include "rr/rrLogger.h"
#include "telPlugin.h"
#include "telUtils.h"
#include "telProperty.h"
#include "../../source/rrAutoPlugin.h"
#include "../../rrAutoInterface/rrRRAuto.h"


using namespace tlp;
using namespace autoplugin;
using namespace std;
using namespace rr;
int main()
{
    string tempFolder(".");
    string sbmlFile("../models/bistable.xml");
	gLog.setLevel(rr::lInfo);
    gLog.enableConsoleLogging();
    gLog.enableFileLogging(joinPath(tempFolder, "bistable.log"));

    try
    {
        string pluginName("tel_auto2000");

        //A Plugin manager, using a roadrunner instance
        PluginManager pm("../plugins");

        //Load auto plugin
        if(!pm.load(pluginName))
        {
            Log(rr::lError)<<"Failed to load plugin: "<<pluginName;
            return 0;
        }

        //Get a plugin handle and get some plugin info
        AutoPlugin* autoPlugin = (AutoPlugin*) pm.getPlugin(pluginName);
        if(!autoPlugin)
        {
            Log(rr::lError)<<"Problem..";
            throw("AutoPlugin don't exist");
        }

        //A serious client would check if these calls are succesfull or not

        string sbml = getFileContent(sbmlFile);

        //Various plugin constants
        autoPlugin->setProperty("SBML", sbml.c_str());
        autoPlugin->setProperty("TempFolder", tempFolder.c_str());
        autoPlugin->setProperty("KeepTempFiles", "false");

        //Specific auto parameters
        PropertyBase* para = autoPlugin->getProperty("AutoParameters");
        Properties* autoParas = (Properties*) (para->getValueHandle());

        cout<<autoParas->getNames();

//        RL0->setValueFromString("1.12");

        autoPlugin->setProperty("ScanDirection", "Positive");
        autoPlugin->setProperty("PrincipalContinuationParameter", "k3");
        autoPlugin->setProperty("PCPLowerBound", "1.1");
        autoPlugin->setProperty("PCPUpperBound", "1.4");

        if(!autoPlugin->execute())
        {
            Log(rr::lError)<<"Problem executing the Auto plugin";
            return 0;
        }

        Log(rr::lInfo)<<"Auto plugin is done.";
        Property<string>* biD = (Property<string>*) autoPlugin->getProperty("BiFurcationDiagram");
        cout<<"BIFURCATION DIAGRAM\n"<< biD->getValue();

        cout<<"\n\nAUTO 2000 is unloading...\n";
        //Check plugin data..
        pm.unload(autoPlugin);
    }
    catch(rr::Exception& ex)
    {
        Log(rr::lError)<<ex.getMessage();
    }
    catch(Poco::Exception& ex)
    {
        Log(rr::lError)<<"Problem..."<<ex.message();
    }
    catch(...)
    {
        Log(rr::lError)<<"Bad problem...!";
    }

     pause(true);
    return 0;
}
