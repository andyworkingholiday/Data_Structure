#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->tabWidget_3->setCurrentIndex(0);
    ui->tabWidget_4->setCurrentIndex(0);
}

MainDialog::~MainDialog()
{
    delete ui;
}

int MainDialog::OpenInFile(char* fileName) {
    m_InFile.open(fileName);
    if (m_InFile) return 1;
    else return 0;
}

// Open a file by file descriptor as an output file.
int MainDialog::OpenOutFile(char* fileName) {
    m_OutFile.open(fileName);
    if (m_OutFile) return 1;
    else return 0;
}

// Open a file as a read mode, read all data on the file, and set list by the data.
int MainDialog::LoadDB() {

    MasterList.MakeEmpty();
    PlaceList.MakeEmpty();
    TempList.MakeEmpty(); // 모든 배열들을 초기화해준다 (불러올거기 때문)

    ItemType t;
    stringstream sItemFileName;
    sItemFileName << "DB\\USERITEMS\\" << User.GetID() << ".txt";
    string Itemfile = sItemFileName.str();

    if (OpenInFile((char*)Itemfile.c_str())){
        // 파일의 모든 내용을 읽어 list에 추가
        while (!m_InFile.eof()) {
            // List에 주소들의 정보가 들어있는 structure 저장
            if (m_InFile.eof()) break;
            t.ReadDataFromFile(m_InFile);

            if (t.GetContainerId() == -1) TempList.Add(t);
            else AddItemToMasterList(t);
        }
    }

    ShowTempGui();
    ShowMasterGui();
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->tabWidget_3->setCurrentIndex(0);
    ui->tabWidget_4->setCurrentIndex(0);
    // file close
    m_InFile.close();
    return 1;
}

// Open a file as a write mode, and write all data into the file,
int MainDialog::SaveDB() {

    ItemType t;
    stringstream sItemFileName;
    sItemFileName << "DB\\USERITEMS\\" << User.GetID() << ".txt";
    string Itemfile = sItemFileName.str();

    if (!OpenOutFile((char*)Itemfile.c_str())) return 0;


    DoublySortedLinkedList<ItemType> All;

    DoublyIterator<ItemType> itor = MasterList;
    DoublyIterator<ItemType> itor2= TempList;
    int len_master = MasterList.GetLength();
    int len_temp = TempList.GetLength();
    int len_all = len_master + len_temp;

    while (len_master--) {
        t = itor.Next();
        All.Add(t);
    }

    while(len_temp--) {
        t=itor2.Next();
        All.Add(t);
    }

    ItemType CurData;
    DoublyIterator<ItemType> itor_all = All;
    while(len_all--) {
        CurData = itor_all.Next();
        if (len_all != 0) CurData.WriteDataToFile(m_OutFile);
        else if (len_all == 0) CurData.WriteDataToFileLast(m_OutFile);
    }

    m_OutFile.close();

    return 1;
}

void MainDialog::SetUser(UserType user) {
    this->User=user;
}

string MainDialog::SetTimeFromSystem() {
    SYSTEMTIME time;
    GetLocalTime(&time);

    stringstream sTime;

    if (time.wMonth < 10)
        sTime << time.wYear << "0" << time.wMonth;
    else
        sTime << time.wYear << time.wMonth;

    // day가 한자리 수일 경우 두자리 표시를 위해 0을 붙임.
    if (time.wDay < 10)
        sTime << "0" << time.wDay;
    else
        sTime << time.wDay;

    // hour가 한자리 수일 경우 두자리 표시를 위해 0을 붙임.
    if (time.wHour < 10)
        sTime << "0" << time.wHour;
    else
        sTime << time.wHour;

    // minute가 한자리 수일 경우 두자리 표시를 위해 0을 붙임.
    if (time.wMinute < 10)
        sTime << "0" << time.wMinute;
    else
        sTime << time.wMinute;

    // second가 한자리 수일 경우 두자리 표시를 위해 0을 붙임.
    if (time.wSecond < 10)
        sTime << "0" << time.wSecond;
    else
        sTime << time.wSecond;


    string Register = sTime.str();
    string year = Register.substr(0, 4);
    string month = Register.substr(4, 2);
    string day = Register.substr(6, 2);
    string hour = Register.substr(8, 2);
    string minute = Register.substr(10, 2);
    string second = Register.substr(12);

    string RegisterTime=year+"년 "+month+"월 "+day+"일 "+hour+"시 "+minute+"분";
    return RegisterTime;
}

void MainDialog::DisplayItembyLocation(int n) {
    ui->LivingRoomTable->clearContents();
    ui->KitchenTable->clearContents();
    ui->BathRoomTable->clearContents();
    ui->BedRoomTable->clearContents();
    ui->LibraryTable->clearContents();
    ui->EtcTable->clearContents();

    int livingNum=0;
    int KitchenNum=0;
    int BathNum=0;
    int BedNum=0;
    int LibNum=0;
    int EtcNum=0;

    DoublyIterator<ItemType> itor = MasterList;
    ItemType CurData;
    int len = MasterList.GetLength();

    for(int i=1; i<=len; i++) {
        CurData=itor.Next();
        int storage=CurData.GetStorageId();
        if(storage==1) livingNum++;
        else if(storage==2) KitchenNum++;
        else if(storage==3) BathNum++;
        else if(storage==4) BedNum++;
        else if(storage==5) LibNum++;
        else EtcNum++;


        int iusage=CurData.GetUsage();
        int inum=CurData.GetItemNum();
        string sname=CurData.GetName();

        QString usage,name,num;

        if(iusage==1) usage="Furniture";
        else if(iusage==2) usage="Electric";
        else if(iusage==3) usage="Clothes";
        else if(iusage==4) usage="Books";
        else if(iusage==5) usage="Bath";
        else if(iusage==6) usage="Cosmetics";
        else if(iusage==7) usage="Stationery";
        else if(iusage==8) usage="Food";
        else if(iusage==9) usage="Exercise";
        else usage="Etc";

        num=QString::number(inum);

        name=QString::fromStdString(sname);

        if(storage==1) ui->LivingRoomTable->setRowCount(livingNum);
        else if(storage==2) ui->KitchenTable->setRowCount(KitchenNum);
        else if(storage==3) ui->BathRoomTable->setRowCount(BathNum);
        else if(storage==4) ui->BedRoomTable->setRowCount(BedNum);
        else if(storage==5) ui->LibraryTable->setRowCount(LibNum);
        else ui->EtcTable->setRowCount(EtcNum);

        QTableWidgetItem * numitem = new QTableWidgetItem(num);
        QTableWidgetItem * usageitem = new QTableWidgetItem(usage);
        QTableWidgetItem * nameitem = new QTableWidgetItem(name);

        numitem->setTextAlignment(Qt::AlignCenter);
        usageitem->setTextAlignment(Qt::AlignCenter);
        nameitem->setTextAlignment(Qt::AlignCenter);

        if(storage==1) {
            ui->LivingRoomTable->setItem(livingNum-1, 0, numitem);
            ui->LivingRoomTable->setItem(livingNum-1, 1, usageitem);
            ui->LivingRoomTable->setItem(livingNum-1, 2, nameitem);
        }

        else if(storage==2) {
            ui->KitchenTable->setItem(KitchenNum-1, 0, numitem);
            ui->KitchenTable->setItem(KitchenNum-1, 1, usageitem);
            ui->KitchenTable->setItem(KitchenNum-1, 2, nameitem);
        }

        else if(storage==3) {
            ui->BathRoomTable->setItem(BathNum-1, 0, numitem);
            ui->BathRoomTable->setItem(BathNum-1, 1, usageitem);
            ui->BathRoomTable->setItem(BathNum-1, 2, nameitem);
        }

        else if(storage==4) {
            ui->BedRoomTable->setItem(BedNum-1, 0, numitem);
            ui->BedRoomTable->setItem(BedNum-1, 1, usageitem);
            ui->BedRoomTable->setItem(BedNum-1, 2, nameitem);
        }

        else if(storage==5) {
            ui->LibraryTable->setItem(LibNum-1, 0, numitem);
            ui->LibraryTable->setItem(LibNum-1, 1, usageitem);
            ui->LibraryTable->setItem(LibNum-1, 2, nameitem);
        }

        else {
            ui->EtcTable->setItem(EtcNum-1, 0, numitem);
            ui->EtcTable->setItem(EtcNum-1, 1, usageitem);
            ui->EtcTable->setItem(EtcNum-1, 2, nameitem);
        }
    }

    if(livingNum==0) ui->LivingRoomTable->setRowCount(0);
    if(KitchenNum==0) ui->KitchenTable->setRowCount(0);
    if(BathNum==0) ui->BathRoomTable->setRowCount(0);
    if(BedNum==0) ui->BedRoomTable->setRowCount(0);
    if(LibNum==0) ui->LibraryTable->setRowCount(0);
    if(EtcNum==0) ui->EtcTable->setRowCount(0);



    if(n==0) ui->tabWidget_4->setCurrentIndex(5);
    else ui->tabWidget_4->setCurrentIndex(n-1);

}

string MainDialog::GetRTimeFromItem(ItemType data) {
    string Register=data.GetRtime();
    string year = Register.substr(0, 4);
    string month = Register.substr(4, 2);
    string day = Register.substr(6, 2);
    string hour = Register.substr(8, 2);
    string minute = Register.substr(10, 2);
    string second = Register.substr(12);

    string RegisterTime=year+"년 "+month+"월 "+day+"일 "+hour+"시 "+minute+"분";
    return RegisterTime;
}

void MainDialog::ReadFromGuiMaster(ItemType& data) {
    QString brand,name;
    int usage, place, container, pday, num;
    bool like;

    if(ui->UsageAdd->currentText()=="Furniture") usage=1;
    else if(ui->UsageAdd->currentText()=="Electric") usage=2;
    else if(ui->UsageAdd->currentText()=="Clothes") usage=3;
    else if(ui->UsageAdd->currentText()=="Books") usage=4;
    else if(ui->UsageAdd->currentText()=="Bath") usage=5;
    else if(ui->UsageAdd->currentText()=="Cosmetics") usage=6;
    else if(ui->UsageAdd->currentText()=="Stationery") usage=7;
    else if(ui->UsageAdd->currentText()=="Food") usage=8;
    else if(ui->UsageAdd->currentText()=="Exercise") usage=9;
    else usage=0;

    if(ui->StorageAdd->currentText()=="LivingRoom") place = 1;
    else if(ui->StorageAdd->currentText()=="Kitchen") place = 2;
    else if(ui->StorageAdd->currentText()=="BathRoom") place = 3;
    else if(ui->StorageAdd->currentText()=="BedRoom") place = 4;
    else if(ui->StorageAdd->currentText()=="Library") place = 5;
    else place = 0;

    container=ui->ContainerAdd->text().toInt();
    pday=ui->DayAdd->date().toString("yyyyMMdd").toInt();
    num=ui->NumberAdd->text().toInt();
    brand=ui->BrandAdd->text();
    name=ui->NameAdd->text();
    string bbrand=brand.toStdString();
    string nname=name.toStdString();

    if(ui->LikeAdd->currentText()=="Like") like=true;
    else like=false;

    data.SetRecord(usage,place,container,"0",pday,bbrand,nname,like,"0",num);
    data.SetTimeFromSystem();
}

void MainDialog::ReadFromGuiTemp(ItemType &data) {
    QString brand,name;
    int usage, pday, num;
    bool like;

    if(ui->UsageAdd->currentText()=="Furniture") usage=1;
    else if(ui->UsageAdd->currentText()=="Electric") usage=2;
    else if(ui->UsageAdd->currentText()=="Clothes") usage=3;
    else if(ui->UsageAdd->currentText()=="Books") usage=4;
    else if(ui->UsageAdd->currentText()=="Bath") usage=5;
    else if(ui->UsageAdd->currentText()=="Cosmetics") usage=6;
    else if(ui->UsageAdd->currentText()=="Stationery") usage=7;
    else if(ui->UsageAdd->currentText()=="Food") usage=8;
    else if(ui->UsageAdd->currentText()=="Exercise") usage=9;
    else usage=0;

    pday=ui->DayAdd->date().toString("yyyyMMdd").toInt();
    num=ui->NumberAdd->text().toInt();
    brand=ui->BrandAdd->text();
    name=ui->NameAdd->text();
    string bbrand=brand.toStdString();
    string nname=name.toStdString();

    if(ui->LikeAdd->currentText()=="Like") like=true;
    else like=false;

    data.SetRecord(usage,0,-1,"0",pday,bbrand,nname,like,"0",num);
    data.SetTimeFromSystem();
}

void MainDialog::ReadFromGuiChange(ItemType &data) {
    QString brand,name;
    int usage, place, container, pday, num;
    bool like;

    if(ui->UsageChange->currentText()=="Furniture") usage=1;
    else if(ui->UsageChange->currentText()=="Electric") usage=2;
    else if(ui->UsageChange->currentText()=="Clothes") usage=3;
    else if(ui->UsageChange->currentText()=="Books") usage=4;
    else if(ui->UsageChange->currentText()=="Bath") usage=5;
    else if(ui->UsageChange->currentText()=="Cosmetics") usage=6;
    else if(ui->UsageChange->currentText()=="Stationery") usage=7;
    else if(ui->UsageChange->currentText()=="Food") usage=8;
    else if(ui->UsageChange->currentText()=="Exercise") usage=9;
    else usage=0;

    if(ui->StorageChange->currentText()=="LivingRoom") place = 1;
    else if(ui->StorageChange->currentText()=="Kitchen") place = 2;
    else if(ui->StorageChange->currentText()=="BathRoom") place = 3;
    else if(ui->StorageChange->currentText()=="BedRoom") place = 4;
    else if(ui->StorageChange->currentText()=="Library") place = 5;
    else place = 0;

    container=ui->ContainerChange->text().toInt();
    pday=ui->DayChange->date().toString("yyyyMMdd").toInt();
    num=ui->NumberChange->text().toInt();
    brand=ui->BrandChange->text();
    name=ui->NameChange->text();
    string bbrand=brand.toStdString();
    string nname=name.toStdString();

    if(ui->LikeChange->currentText()=="Like") like=true;
    else like=false;

    data.SetUsage(usage);
    data.SetStorageId(place);
    data.SetContainerId(container);
    data.SetPday(pday);
    data.SetBrand(bbrand);
    data.SetName(nname);
    data.SetHeart(like);
    data.SetItemNum(num);

}

void MainDialog::ShowMasterGui() {
    ui->MasterTable->clearContents();

    DoublyIterator<ItemType> itor = MasterList;
    ItemType CurData;
    int len = MasterList.GetLength();

    for(int i=1; i<=len; i++) {
        CurData=itor.Next();
        int iusage=CurData.GetUsage();
        int iplace=CurData.GetStorageId();
        int icont=CurData.GetContainerId();
        int ipday=CurData.GetPday();
        int inum=CurData.GetItemNum();
        string srtime=GetRTimeFromItem(CurData);
        string sbrand=CurData.GetBrand();
        string sname=CurData.GetName();
        bool blike=CurData.GetHeart();

        QString usage, place, container, qrtime,pday,brand,name,like,num;

        if(iusage==1) usage="Furniture";
        else if(iusage==2) usage="Electric";
        else if(iusage==3) usage="Clothes";
        else if(iusage==4) usage="Books";
        else if(iusage==5) usage="Bath";
        else if(iusage==6) usage="Cosmetics";
        else if(iusage==7) usage="Stationery";
        else if(iusage==8) usage="Food";
        else if(iusage==9) usage="Exercise";
        else usage="Etc";


        if(iplace==1) place="LivingRoom";
        else if(iplace==2) place="Kitchen";
        else if(iplace==3) place="BathrRoom";
        else if(iplace==4) place="BedRoom";
        else if(iplace==5) place="Library";
        else place="Etc";

        container=QString::number(icont);
        qrtime=QString::fromStdString(srtime);

        pday=QString::number(ipday);
        string spday=pday.toStdString();
        string year=spday.substr(0,4);
        string month=spday.substr(4,2);
        string day=spday.substr(6);
        string sspday=year+"년 "+month+"월 "+day+"일";
        pday=QString::fromStdString(sspday);

        num=QString::number(inum);
        brand=QString::fromStdString(sbrand);
        name=QString::fromStdString(sname);
        if(blike) like="Y";
        else like="N";

        ui->MasterTable->setRowCount(i);

        QTableWidgetItem * numitem = new QTableWidgetItem(num);
        QTableWidgetItem * usageitem = new QTableWidgetItem(usage);
        QTableWidgetItem * placeitem = new QTableWidgetItem(place);
        QTableWidgetItem * containeritem = new QTableWidgetItem(container);
        QTableWidgetItem * branditem = new QTableWidgetItem(brand);
        QTableWidgetItem * nameitem = new QTableWidgetItem(name);
        QTableWidgetItem * qrtimeitem = new QTableWidgetItem(qrtime);
        QTableWidgetItem * pdayitem = new QTableWidgetItem(pday);
        QTableWidgetItem * likeitem = new QTableWidgetItem(like);

        numitem->setTextAlignment(Qt::AlignCenter);
        usageitem->setTextAlignment(Qt::AlignCenter);
        placeitem->setTextAlignment(Qt::AlignCenter);
        containeritem->setTextAlignment(Qt::AlignCenter);
        branditem->setTextAlignment(Qt::AlignCenter);
        nameitem->setTextAlignment(Qt::AlignCenter);
        qrtimeitem->setTextAlignment(Qt::AlignCenter);
        pdayitem->setTextAlignment(Qt::AlignCenter);
        likeitem->setTextAlignment(Qt::AlignCenter);

        ui->MasterTable->setItem(i-1, 0, numitem);
        ui->MasterTable->setItem(i-1, 1, usageitem);
        ui->MasterTable->setItem(i-1, 2, placeitem);
        ui->MasterTable->setItem(i-1, 3, containeritem);
        ui->MasterTable->setItem(i-1, 4, branditem);
        ui->MasterTable->setItem(i-1, 5, nameitem);
        ui->MasterTable->setItem(i-1, 6, qrtimeitem);
        ui->MasterTable->setItem(i-1, 7, pdayitem);
        ui->MasterTable->setItem(i-1, 8, likeitem);

    }
    if(len==0) ui->MasterTable->setRowCount(0);
    ui->tabWidget_3->setCurrentIndex(0);

}

void MainDialog::ShowTempGui() {
    ui->TempTable->clearContents();


    DoublyIterator<ItemType> itor=TempList;
    ItemType CurData;
    int len = TempList.GetLength();

    for(int i=1; i<=len; i++) {
        CurData=itor.Next();
        int iusage=CurData.GetUsage();
        int ipday=CurData.GetPday();
        int inum=CurData.GetItemNum();
        string srtime=GetRTimeFromItem(CurData);
        string sbrand=CurData.GetBrand();
        string sname=CurData.GetName();
        bool blike=CurData.GetHeart();

        QString usage, qrtime,pday,brand,name,like,num;

        if(iusage==1) usage="Furniture";
        else if(iusage==2) usage="Electric";
        else if(iusage==3) usage="Clothes";
        else if(iusage==4) usage="Books";
        else if(iusage==5) usage="Bath";
        else if(iusage==6) usage="Cosmetics";
        else if(iusage==7) usage="Stationery";
        else if(iusage==8) usage="Food";
        else if(iusage==9) usage="Exercise";
        else usage="Etc";

        qrtime=QString::fromStdString(srtime);
        pday=QString::number(ipday);
        string spday=pday.toStdString();
        string year=spday.substr(0,4);
        string month=spday.substr(4,2);
        string day=spday.substr(6);
        string sspday=year+"년 "+month+"월 "+day+"일";
        pday=QString::fromStdString(sspday);

        num=QString::number(inum);
        brand=QString::fromStdString(sbrand);
        name=QString::fromStdString(sname);
        if(blike) like="Y";
        else like="N";

        ui->TempTable->setRowCount(i);
        QTableWidgetItem * numitem = new QTableWidgetItem(num);
        QTableWidgetItem * usageitem = new QTableWidgetItem(usage);
        QTableWidgetItem * branditem = new QTableWidgetItem(brand);
        QTableWidgetItem * nameitem = new QTableWidgetItem(name);
        QTableWidgetItem * qrtimeitem = new QTableWidgetItem(qrtime);
        QTableWidgetItem * pdayitem = new QTableWidgetItem(pday);
        QTableWidgetItem * likeitem = new QTableWidgetItem(like);

        numitem->setTextAlignment(Qt::AlignCenter);
        usageitem->setTextAlignment(Qt::AlignCenter);
        branditem->setTextAlignment(Qt::AlignCenter);
        nameitem->setTextAlignment(Qt::AlignCenter);
        qrtimeitem->setTextAlignment(Qt::AlignCenter);
        pdayitem->setTextAlignment(Qt::AlignCenter);
        likeitem->setTextAlignment(Qt::AlignCenter);

        ui->TempTable->setItem(i-1, 0, numitem);
        ui->TempTable->setItem(i-1, 1, usageitem);
        ui->TempTable->setItem(i-1, 2, branditem);
        ui->TempTable->setItem(i-1, 3, nameitem);
        ui->TempTable->setItem(i-1, 4, qrtimeitem);
        ui->TempTable->setItem(i-1, 5, pdayitem);
        ui->TempTable->setItem(i-1, 6, likeitem);

    }
    if(len==0) ui->TempTable->setRowCount(0);
    ui->tabWidget_3->setCurrentIndex(1);
}

void MainDialog::ShowSearchGui(ItemType data, int index) {
    int iusage=data.GetUsage();
    int iplace=data.GetStorageId();
    int icont=data.GetContainerId();
    int ipday=data.GetPday();
    int inum=data.GetItemNum();
    string srtime=GetRTimeFromItem(data);
    string sbrand=data.GetBrand();
    string sname=data.GetName();
    bool blike=data.GetHeart();

    QString usage, place, container, qrtime,pday,brand,name,like,num;

    if(iusage==1) usage="Furniture";
    else if(iusage==2) usage="Electric";
    else if(iusage==3) usage="Clothes";
    else if(iusage==4) usage="Books";
    else if(iusage==5) usage="Bath";
    else if(iusage==6) usage="Cosmetics";
    else if(iusage==7) usage="Stationery";
    else if(iusage==8) usage="Food";
    else if(iusage==9) usage="Exercise";
    else usage="Etc";


    if(iplace==1) place="LivingRoom";
    else if(iplace==2) place="Kitchen";
    else if(iplace==3) place="BathrRoom";
    else if(iplace==4) place="BedRoom";
    else if(iplace==5) place="Library";
    else place="Etc";

    container=QString::number(icont);
    qrtime=QString::fromStdString(srtime);

    pday=QString::number(ipday);
    string spday=pday.toStdString();
    string year=spday.substr(0,4);
    string month=spday.substr(4,2);
    string day=spday.substr(6);
    string sspday=year+"년 "+month+"월 "+day+"일";
    pday=QString::fromStdString(sspday);

    num=QString::number(inum);
    brand=QString::fromStdString(sbrand);
    name=QString::fromStdString(sname);
    if(blike) like="Y";
    else like="N";

    ui->SearchTable->setRowCount(index);

    QTableWidgetItem * numitem = new QTableWidgetItem(num);
    QTableWidgetItem * usageitem = new QTableWidgetItem(usage);
    QTableWidgetItem * placeitem = new QTableWidgetItem(place);
    QTableWidgetItem * containeritem = new QTableWidgetItem(container);
    QTableWidgetItem * branditem = new QTableWidgetItem(brand);
    QTableWidgetItem * nameitem = new QTableWidgetItem(name);
    QTableWidgetItem * qrtimeitem = new QTableWidgetItem(qrtime);
    QTableWidgetItem * pdayitem = new QTableWidgetItem(pday);
    QTableWidgetItem * likeitem = new QTableWidgetItem(like);

    numitem->setTextAlignment(Qt::AlignCenter);
    usageitem->setTextAlignment(Qt::AlignCenter);
    placeitem->setTextAlignment(Qt::AlignCenter);
    containeritem->setTextAlignment(Qt::AlignCenter);
    branditem->setTextAlignment(Qt::AlignCenter);
    nameitem->setTextAlignment(Qt::AlignCenter);
    qrtimeitem->setTextAlignment(Qt::AlignCenter);
    pdayitem->setTextAlignment(Qt::AlignCenter);
    likeitem->setTextAlignment(Qt::AlignCenter);

    ui->SearchTable->setItem(index-1, 0, numitem);
    ui->SearchTable->setItem(index-1, 1, usageitem);
    ui->SearchTable->setItem(index-1, 2, placeitem);
    ui->SearchTable->setItem(index-1, 3, containeritem);
    ui->SearchTable->setItem(index-1, 4, branditem);
    ui->SearchTable->setItem(index-1, 5, nameitem);
    ui->SearchTable->setItem(index-1, 6, qrtimeitem);
    ui->SearchTable->setItem(index-1, 7, pdayitem);
    ui->SearchTable->setItem(index-1, 8, likeitem);

}

int MainDialog::AddItemToMaster() {
    ItemType data;

    if (MasterList.IsFull()) {
        printf("\tMaster List is Full\n"); // 마스터 리스트 가득 찼을 시 해당 문구 출력
        return 0;
    }

    else {
        ReadFromGuiMaster(data);
        if(!MasterList.Get(data) && !TempList.Get(data)) {
            int location = data.GetStorageId();
            int container = data.GetContainerId();
            StorageType stype;
            ContainerType ctype;
            stype.SetStorageId(location); // location 위치 받아오기
            ctype.SetContainerId(container); // 컨테이너 번호 받아오기

            SimpleItemType simpledata;
            int sUsage = data.GetUsage();
            string sName = data.GetName();
            int sItemNumber = data.GetItemNum();
            simpledata.SetRecord(sUsage, sName, sItemNumber); //sdata에 data와 겹치는 변수들을 넣어준다.

            if (PlaceList.Get(stype)) { // 검색한 장소가 이미 등록이 되있을 시
                if (stype.SearchContainer(ctype)) { // 컨테이너 번호가 이미 등록되어 있을 시
                    ctype.AddItem(simpledata); // 해당 컨테이너에 아이템 추가
                    stype.UpdateContainer(ctype); // 아이템 추가한 컨테이너로 업데이트
                    PlaceList.Replace(stype); // 장소 업데이트
                }

                else { // 컨테이너 번호가 처음 등록될 시
                    ctype.AddItem(simpledata); // 해당 컨테이너에 아이템 추가
                    stype.AddContainer(ctype); // 아이템 추가한 컨테이너 새로 추가
                    PlaceList.Replace(stype); // 장소 업데이트
                }
            }

            else { // 장소가 처음 등록될 시
                ctype.AddItem(simpledata); //해당 컨테이너에 아이템 추가
                stype.AddContainer(ctype); // 아이템 추가한 컨테이너 새로 추가
                PlaceList.Add(stype); // 장소 추가
            }

            MasterList.Add(data);
            DisplayItembyLocation(location);
            return 1;

        }

        else return -1;

    }
}

int MainDialog::AddItemToMasterList(ItemType data) {
    if (MasterList.IsFull()) {
        printf("\tMaster List is Full\n"); // 마스터 리스트 가득 찼을 시 해당 문구 출력
        return 0;
    }

    else {
        if(!MasterList.Get(data)) {
            int location = data.GetStorageId();
            int container = data.GetContainerId();
            StorageType stype;
            ContainerType ctype;
            stype.SetStorageId(location); // location 위치 받아오기
            ctype.SetContainerId(container); // 컨테이너 번호 받아오기

            SimpleItemType simpledata;
            int sUsage = data.GetUsage();
            string sName = data.GetName();
            int sItemNumber = data.GetItemNum();
            simpledata.SetRecord(sUsage, sName, sItemNumber); //sdata에 data와 겹치는 변수들을 넣어준다.

            if (PlaceList.Get(stype)) { // 검색한 장소가 이미 등록이 되있을 시
                if (stype.SearchContainer(ctype)) { // 컨테이너 번호가 이미 등록되어 있을 시
                    ctype.AddItem(simpledata); // 해당 컨테이너에 아이템 추가
                    stype.UpdateContainer(ctype); // 아이템 추가한 컨테이너로 업데이트
                    PlaceList.Replace(stype); // 장소 업데이트
                }

                else { // 컨테이너 번호가 처음 등록될 시
                    ctype.AddItem(simpledata); // 해당 컨테이너에 아이템 추가
                    stype.AddContainer(ctype); // 아이템 추가한 컨테이너 새로 추가
                    PlaceList.Replace(stype); // 장소 업데이트
                }
            }

            else { // 장소가 처음 등록될 시
                ctype.AddItem(simpledata); //해당 컨테이너에 아이템 추가
                stype.AddContainer(ctype); // 아이템 추가한 컨테이너 새로 추가
                PlaceList.Add(stype); // 장소 추가
            }

            MasterList.Add(data);
            DisplayItembyLocation(location);
            return 1;

        }

        else return -1;

    }
}

int MainDialog::AddItemToTemp() {
    ItemType data;
    if (TempList.IsFull()) {
        printf("\tTemporary List is Full\n"); //TempList 꽉찼을 시 함수 종료
        return 0;
    }

    else {
        ReadFromGuiTemp(data);
        if(!MasterList.Get(data) && !TempList.Get(data)) {
            TempList.Add(data);
            return 1;
        }

        else return -1;
    }
}

int MainDialog::DeleteItem() {
    ItemType data;
    StorageType stype;
    ContainerType ctype;
    SimpleItemType Sdata;
    int num;
    num=ui->KeyDelete->text().toInt();
    data.SetItemNum(num);

    if (MasterList.Delete(data)) { // MasterList에 해당 data 있을 시 삭제하면서 동시에 data 읽어옴
        int location = data.GetStorageId();
        int container = data.GetContainerId();
        int iNum = data.GetItemNum();
        Sdata.SetItemNum(iNum);

        stype.SetStorageId(location); // 위치 set
        ctype.SetContainerId(container); // 컨테이너 set
        PlaceList.Get(stype);
        stype.SearchContainer(ctype); // stype의 장소를 Set 하고 장소에 따른 아이템을 찾는다.

        ctype.DeleteItem(Sdata); // 반드시 data가 있을 수 밖에 없으므로 해당 Sdata 삭제
        stype.UpdateContainer(ctype);
        PlaceList.Replace(stype); //삭제완료 후 Cdata로 Container List 새로 갱신
        DisplayItembyLocation(location);
        return 1;
    }

    else if(TempList.Delete(data)) {
        return 2;
    }

    else {
        return 0;
    }

}

//Replace item from MasterList
int MainDialog::ReplaceItemFromMaster() {
    ItemType data, origin;
    StorageType stype;
    ContainerType ctype;
    SimpleItemType sdata;

    int num;
    num=ui->NumberChange->text().toInt();
    data.SetItemNum(num);

    if (MasterList.Get(data)) { // MasterList에 해당 data 있을 시
        ReadFromGuiChange(data);

        origin.SetItemNum(data.GetItemNum()); // 원래있던 아이템을 찾기 위해 장소 set
        MasterList.Get(origin);
        MasterList.Replace(data); // 마스터리스트의 아이템 갱신

        //기존 내용 삭제
        stype.SetStorageId(origin.GetContainerId());
        ctype.SetContainerId(origin.GetContainerId());
        sdata.SetItemNum(origin.GetItemNum());
        PlaceList.Get(stype);
        stype.SearchContainer(ctype);
        ctype.DeleteItem(sdata);
        stype.UpdateContainer(ctype);
        PlaceList.Replace(stype);

        //새로운 데이터 추가
        int location = data.GetStorageId();
        int container = data.GetContainerId();
        int iNum = data.GetItemNum();
        string iName = data.GetName();
        int iUsage = data.GetUsage();
        sdata.SetRecord(iUsage, iName, iNum); //갱신될 Container List에 새로운 레코드 복사

        stype.SetStorageId(location);
        ctype.SetContainerId(container);

        // 삭제후 추가하는 함수로 Add와 원리가 같다.
        if (PlaceList.Get(stype)) {
            if (stype.SearchContainer(ctype)) {
                ctype.AddItem(sdata);
                stype.UpdateContainer(ctype);
                PlaceList.Replace(stype);
            }

            else {
                ctype.AddItem(sdata);
                stype.AddContainer(ctype);
                PlaceList.Replace(stype);
            }
        }

        else {
            ctype.AddItem(sdata);
            stype.AddContainer(ctype);
            PlaceList.Add(stype);
        }
        DisplayItembyLocation(location);
        return 1;
    }

    else {
        return 0;
    }
}

void MainDialog::on_AddPush_clicked()
{
    int a=AddItemToMaster();
    if(a==0)
        QMessageBox::warning(this, "Add", "Master List is Full!");
    else if(a==-1) {
        QMessageBox::warning(this, "Add", "Same Keynumber has found!");
    }

    else
        ShowMasterGui();
}

void MainDialog::on_AddPush_2_clicked()
{
    int a=AddItemToTemp();
    if(a==0)
        QMessageBox::warning(this, "Add", "Temporary List is Full!");
    else if(a==-1) {
        QMessageBox::warning(this, "Add", "Same Keynumber has found!");
    }

    else
        ShowTempGui();
}

void MainDialog::on_DeletePush_clicked()
{
    int a=DeleteItem();
    if(a==0)
        QMessageBox::warning(this, "Delete", "There is No Item you want to Delete!");
    if(a==1) {
        ShowMasterGui();
    }
    if(a==2) {
        ShowTempGui();
    }
}

void MainDialog::on_AddPush_3_clicked()
{
    ItemType data;
    int container, place, num;
    num=ui->TempNumberAdd->text().toInt();
    data.SetItemNum(num);

    if(TempList.Get(data)) {
        if(ui->TempStorageAdd->currentText()=="LivingRoom") place = 1;
        else if(ui->TempStorageAdd->currentText()=="Kitchen") place = 2;
        else if(ui->TempStorageAdd->currentText()=="BathRoom") place = 3;
        else if(ui->TempStorageAdd->currentText()=="BedRoom") place = 4;
        else if(ui->TempStorageAdd->currentText()=="Library") place = 5;
        else place = 0;

        container=ui->TempContainerAdd->text().toInt();
        data.SetStorageId(place);
        data.SetContainerId(container);

        int a=AddItemToMasterList(data);

        if(a==1) {
            TempList.Delete(data);
            ShowMasterGui();
            ShowTempGui();
            DisplayItembyLocation(place);
        }

        else {
            QMessageBox::warning(this, "Move", "MaterList is Full!");
        }

    }

    else {
        QMessageBox::warning(this, "Move", "There is No Item you want to Move!");
    }



}

void MainDialog::on_ChangePush_clicked()
{
    int a=ReplaceItemFromMaster();
    if(a==1) {
        QMessageBox::information(this, "Change", "Change Success!");
        ShowMasterGui();
    }

    else
        QMessageBox::warning(this, "Change", "There is No Item you want to Change!");
}

void MainDialog::on_FindByUsage_clicked()
{
    int usage, place;

    if(ui->UsageFind->currentText()=="Furniture") usage=1;
    else if(ui->UsageFind->currentText()=="Electric") usage=2;
    else if(ui->UsageFind->currentText()=="Clothes") usage=3;
    else if(ui->UsageFind->currentText()=="Books") usage=4;
    else if(ui->UsageFind->currentText()=="Bath") usage=5;
    else if(ui->UsageFind->currentText()=="Cosmetics") usage=6;
    else if(ui->UsageFind->currentText()=="Stationery") usage=7;
    else if(ui->UsageFind->currentText()=="Food") usage=8;
    else if(ui->UsageFind->currentText()=="Exercise") usage=9;
    else if(ui->UsageFind->currentText()=="None") usage=-1;
    else usage=0;

    if(ui->StorageFind->currentText()=="LivingRoom") place = 1;
    else if(ui->StorageFind->currentText()=="Kitchen") place = 2;
    else if(ui->StorageFind->currentText()=="BathRoom") place = 3;
    else if(ui->StorageFind->currentText()=="BedRoom") place = 4;
    else if(ui->StorageFind->currentText()=="Library") place = 5;
    else if(ui->StorageFind->currentText()=="None") place = -1;
    else place = 0;

    ui->SearchTable->clearContents();

    if(place ==-1 && usage==-1) {
        DoublyIterator<ItemType> itor = MasterList;
        ItemType CurData;
        int len = MasterList.GetLength();
        for(int i=1; i<=len; i++) {
            CurData=itor.Next();
            ShowSearchGui(CurData,i);
        }
        ui->tabWidget_3->setCurrentIndex(2);
    }

    else if(usage!=-1 && place == -1) {
        DoublyIterator<ItemType> itor = MasterList;
        ItemType CurData;
        int len = MasterList.GetLength();
        int index=1;
        bool found=false;
        for(int i=1; i<=len; i++) {
            CurData=itor.Next();
            int Curusage=CurData.GetUsage();
            if(Curusage==usage) {
                ShowSearchGui(CurData,index);
                index++;
                found=true;
            }
        }

        if(!found) ui->SearchTable->setRowCount(0);
        ui->tabWidget_3->setCurrentIndex(2);
    }

    else if(usage==-1 && place != -1) {
        DoublyIterator<ItemType> itor = MasterList;
        ItemType CurData;
        int len = MasterList.GetLength();
        int index=1;
        bool found=false;
        for(int i=1; i<=len; i++) {
            CurData=itor.Next();
            int CurPlace=CurData.GetStorageId();
            if(CurPlace==place) {
                ShowSearchGui(CurData,index);
                index++;
                found=true;
            }
        }
        if(!found) ui->SearchTable->setRowCount(0);
        ui->tabWidget_3->setCurrentIndex(2);
    }

    else {
        DoublyIterator<ItemType> itor = MasterList;
        ItemType CurData;
        int len = MasterList.GetLength();
        int index=1;
        bool found=false;
        for(int i=1; i<=len; i++) {
            CurData=itor.Next();
            int CurPlace=CurData.GetStorageId();
            int CurUsage=CurData.GetUsage();
            if(CurPlace==place && CurUsage==usage) {
                ShowSearchGui(CurData,index);
                index++;
                found=true;
            }
        }
        if(!found) {
            ui->SearchTable->setRowCount(0);
            QMessageBox::warning(this, "Find", "There is No Item you want to Find!");
        }

        ui->tabWidget_3->setCurrentIndex(2);
    }
}

void MainDialog::on_FindNamePush_clicked()
{
    QString name;
    name=ui->NameFind->text();
    string nname=name.toStdString();
    ui->SearchTable->clearContents();

    DoublyIterator<ItemType> itor = MasterList;
    ItemType CurData;
    int len = MasterList.GetLength();
    int index=1;
    bool found=false;
    for(int i=1; i<=len; i++) {
        CurData=itor.Next();
        string Curname=CurData.GetName();
        if(Curname.find(nname)!=-1) {
            ShowSearchGui(CurData,index);
            index++;
            found=true;
        }
    }

    if(!found) {
        ui->SearchTable->setRowCount(0);
        QMessageBox::warning(this, "Find", "There is No Item you want to Find!");
    }

    ui->tabWidget_3->setCurrentIndex(2);
}

void MainDialog::on_FindNumerPush_clicked()
{
    int num;
    num=ui->KeyFind->text().toInt();
    ui->SearchTable->clearContents();

    DoublyIterator<ItemType> itor = MasterList;
    ItemType CurData;
    int len = MasterList.GetLength();
    bool found=false;
    for(int i=1; i<=len; i++) {
        CurData=itor.Next();
        int Curnum=CurData.GetItemNum();
        if(Curnum==num) {
            ShowSearchGui(CurData,1);
            found=true;
            break;
        }
    }

    if(!found) {
        ui->SearchTable->setRowCount(0);
        QMessageBox::warning(this, "Find", "There is No Item you want to Find!");
    }

    ui->tabWidget_3->setCurrentIndex(2);
}

void MainDialog::on_FindByDate_clicked()
{
    int psday,peday;
    psday=ui->DayStart->date().toString("yyyyMMdd").toInt();
    peday=ui->DayEnd->date().toString("yyyyMMdd").toInt();
    ui->SearchTable->clearContents();

    DoublyIterator<ItemType> itor = MasterList;
    ItemType CurData;
    int len = MasterList.GetLength();
    bool found=false;
    int index=1;
    for(int i=1; i<=len; i++) {
        CurData=itor.Next();
        int Curpday=CurData.GetPday();
        if(Curpday>=psday && Curpday<=peday) {
            ShowSearchGui(CurData,index);
            index++;
            found=true;
        }
    }

    if(!found) {
        ui->SearchTable->setRowCount(0);
        QMessageBox::warning(this, "Find", "There is No Item you want to Find!");
    }

    ui->tabWidget_3->setCurrentIndex(2);

}

void MainDialog::on_SavePush_clicked()
{
    int a= SaveDB();
    if(a==1)
        QMessageBox::information(this, "Save", "Save Success!");
    else
        QMessageBox::warning(this, "Find", "Save Failed!");
}


void MainDialog::on_QuitPush_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,
    "Quit", "Do you want to Save?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes) {
        SaveDB();
        this->close();
    }

    else
        this->close();
}

void MainDialog::on_ChoosePush_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
    ui->PhotoEdit->setText(filename);
}

void MainDialog::on_AddPhotoPush_clicked()
{
    QString pphoto=ui->PhotoEdit->text();

    string photo=pphoto.toStdString();

    int num;
    num=ui->KeyAddPhoto->text().toInt();

    ItemType data;
    data.SetItemNum(num);
    if(MasterList.Get(data) || TempList.Get(data)) {
        ItemType copy = data;
        copy.SetPhoto(photo);
        if(data.GetContainerId()!=-1) {
            MasterList.Delete(data);
            MasterList.Add(copy);
            ShowMasterGui();
            DisplayItembyLocation(copy.GetStorageId());
        }

        else {
            TempList.Delete(data);
            TempList.Add(copy);
            ShowTempGui();
        }

        QMessageBox::information(this, "Add Photo", "Add Success!");
    }
    else
        QMessageBox::warning(this, "Find", "There is No Item you want to Add Photo!");

}
void MainDialog::on_ShowPhotoPush_clicked()
{
    ItemType data;
    int num;
    num=ui->KeyShowPhoto->text().toInt();
    data.SetItemNum(num);

    if(MasterList.Get(data) || TempList.Get(data)) {
        if(data.GetPhoto()=="0") {
            QMessageBox::warning(this, "Show", "There is No Photo!");
            return;
        }

        else {
            string sphoto = data.GetPhoto();
            QString filename;
            filename=QString::fromStdString(sphoto);

            if(QString::compare(filename,QString()) != 0) {
                QImage image;
                bool valid = image.load(filename);

                if(valid) {
                    image=image.scaledToWidth(ui->ImageLabel->width(), Qt::SmoothTransformation);
                    ui->ImageLabel->setPixmap(QPixmap::fromImage(image));
                }

                else {
                    QMessageBox::warning(this, "Show", "Image Import Error!");
                }

            }

        }
    }

    else
        QMessageBox::warning(this, "Find", "There is No Item you want to Show Photo!");




}

void MainDialog::on_DeletePhotoPush_clicked()
{
    int num;
    num=ui->KeyDeletePhoto->text().toInt();

    ItemType data;
    data.SetItemNum(num);
    if(MasterList.Get(data) || TempList.Get(data)) {
        if(data.GetPhoto()=="0") {
            QMessageBox::warning(this, "Show", "The Item doesn't have Photo already");
            return;
        }

        else {
            if(data.GetContainerId()!=-1) {
                MasterList.Delete(data);
                data.SetPhoto("0");
                MasterList.Add(data);
                ShowMasterGui();
                DisplayItembyLocation(data.GetStorageId());
            }

            else {
                TempList.Delete(data);
                data.SetPhoto("0");
                TempList.Add(data);
                ShowTempGui();
            }

            QMessageBox::information(this, "Delete Photo", "Delete"
                                                           " Success!");
        }
    }

    else
        QMessageBox::warning(this, "Delete Photo", "There is No Item you want to Delete Photo!");
}
