#ifndef ERESURSEPACK_H
#define ERESURSEPACK_H
#include <QFile>
#include <QDataStream>
#include "EItem.h"
#include <QList>
#include "SpaceEngine/System/ECore.h"
//#define RESURSE_PACK_DIR static QString _dir__;
//#define RESURSE_PACK_DIR_ACSSES _dir__
/**
 * @brief The EResursePack class класс предстовляет собой
 * интерфейсом между файлом (покетом ресурсов и всеми рисурсами в игре)
 */
class EResursePack
{
private:
    //short _moduleNumber;
    void load();
    QList<EResurse*>* source;
public:
    EResursePack();
    /**
     * @brief getResurse
     * @param id
     * @return вернет ресурс по ид
     */
    static EResurse* getResurse(const ui id);
    static QString& ResursePackDir();
    void save();
    static void bufferClear();
    EResurse* add(const QString& url);
    QList<EResurse*>* getList();
    bool remove(const unsigned int id);
    static QString getName(const ui id, bool translated=false);
    /**
     * @brief chekName проверит занято ли это имя или нет (в соотвецтвии с выбранным языком)
     * @param name проверяемое имя
     * @return вернет истину если емя найдено в пративном случае лож
     */
    static bool chekName(const QString& name);
    ~EResursePack();
};

#endif // ERESURSEPACK_H
