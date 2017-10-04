#ifndef FILEVIEWER__H_
#define FILEVIEWER__H_

#include "TKey.h"

#include "TGPicture.h"
#include "TGListTree.h"
#include "TFile.h"
#include "TGButton.h"
#include "TEnv.h"
#include "TCanvas.h"

#include "TProfile.h"
#include "TProfile2D.h"
#include "TH2.h"
#include "TH1.h"
#include "RQ_OBJECT.h"


#include <map>
#include <iostream>
#include <string>

#include "../include/FileTable.h"

extern TEnv* gEnv;

class TKey;

class FileViewer {
    RQ_OBJECT("FileViewer")

public:
    FileViewer();
    void DrawInFrame(TGCompositeFrame* main_frame);
    void TreeItemDoubleClicked(TGListTreeItem* item, int id);
    void PrintSomething(map<string*, string*>*);

//slot: INTERFACE
    void DisplayInTreeView(map<string*, string*> *t); //*SLOT*

//signal: INTERNAL
    void RemoveSelectedItem(); //*SIGNAL*
    void RemoveAll(); //*SIGNAL*

private:
    TFile* GetRemoteFile(string filepath);
    void AddChildren(TGListTreeItem* parent);
    void OpenFileInTreeView(string remote_file_path, string displayname="");
    void PrintSelectedItem();

    bool IsFileOpen(string s);



    TGCanvas*       file_tree;
    TGViewPort*     view_port;
    TGListTree*     list_tree;
    TGTextButton*   remove_item_button;
    TGTextButton*   remove_all_button;

    map<TGListTreeItem*, TKey*>  tree_items_map;
    map<string, TGListTreeItem*> open_files;

    const TGPicture* popen  = gClient->GetPicture("ofolder_t.xpm");
    const TGPicture* pclose = gClient->GetPicture("folder_t.xpm");
    const TGPicture* ph1    = gClient->GetPicture("h1_t.xpm");
    const TGPicture* ph2    = gClient->GetPicture("h2_t.xpm");
};

#endif