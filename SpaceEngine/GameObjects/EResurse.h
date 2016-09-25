#ifndef ERESURSE_H
#define ERESURSE_H
#include "SpaceEngine/System/ESprite.h"
#include "SpaceEngine/System/ELanguage.h"
#include <QMap>
#define FROM_NAME 0
class EResurse
{
private:
    ui _id;//unikalnii id
    us id_name,id_desc;
protected:
    QString _name, _descript,_url;
    QImage *Picture;
    QMap<us,us> craft;// te elementi kotorie nugni dlya sozdaniya etogo elementa
    // first - id elementa na sozdanie
    // second - kolichestvo
    ui value;
    /**
     * @brief loadImage загрузит картинку
     */
    void loadImage();
    void deleteImage();
public:
    /**
     * @brief EResurse rонструктор
     * @param url путь к основному файлу ()
     * @param name индекс имени ресурса в языковом файле
     * @param val количество в стеке
     * @param descript индекс описания в языковом файле
     */
    explicit EResurse(const QString &url, const ui &id, const ui& name=0, const ui val=1, const ui &descript=0);
    //explicit EResurse(const QString &url, const QString& name="none", const ui val=1, const QString &descript="none");
    /**
     * @brief picture
     * @return  вернет пиутограмму
     */
    QImage* picture();
    /**
     * @brief setValue установит новое число данного ресурса
     * @param val
     */
    void setValue(const ui& val);
    /**
     * @brief getValue
     * @return вернет количество ресурсов в этом стеке
     */
    ui getValue()const;
    /**
     * @brief id вернет ид ресурса
     * @return
     */
    ui id()const;
    /**
     * @brief url
     * @return вернет путь к файу генерации
     */
    const QString& url()const;
    /**
     * @brief getCraft элементы для создания этого элемента
     * @return вернет списов для создания (если он пуст значит предмет оздать нельзя)
     */
    QMap<us,us> * getCraft();
    /**
     * @brief setName установит новое имя
     * @param IndexName индекс нового имени в языковом файле
     */
    void setName(const ui& IndexName);
    /**
     * @brief setDescription установит новое описание
     * @param desc индекс нового описания в языковом файле
     */
    void setDescription(const ui& desc);
    /**
     * @brief name
     * @return вернет имя ресурса (ткст)
     */
    const QString& name();
    /**
     * @brief desc вернет описания ресурса (тест)
     * @return
     */
    const QString& desc();
    /**
     * @brief idName
     * @return вернет ид названия в файле языков
     */
    us idName()const;
    /**
     * @brief idDesc
     * @return вернет ид описание в файле языков
     */
    us idDesc()const;
    ~EResurse();
    friend QDataStream& operator >>(QDataStream &stream,EResurse& res);
    friend QDataStream& operator <<(QDataStream &stream,const EResurse& res);

};

#endif // ERESURSE_H
