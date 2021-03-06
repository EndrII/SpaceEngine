#ifndef CONTUR_H
#define CONTUR_H
#include "EKord.h"
#include <QDataStream>
#include <QVector>
#define TO_RADIAN 0.017453293
/**
 * @brief The EContur class
 * предстоаляет собой контур выбронного обьекта по которому определяються столкновения
*/
// Апроксимация значений EKord
// X -> Radius
// Y -> Ugol (в градусах)
class EContur{
private:
    float *_x,*_y,*base_engle; //базовые данные об Обьекте
    float depchLong;//glubina
    bool depth;// proverka
    EKord edge;//крайняя точка
    QVector<EKord>* points;
    unsigned short FindEdge();//poisk samoi dalnei ticki
public:
    void setPoints(QVector<EKord> *p);
    EContur& operator =(const EContur&right);
    unsigned int size()const;
    friend QDataStream& operator>>(QDataStream& stream,EContur& cont);
    friend QDataStream& operator<<(QDataStream& stream,const EContur& cont);
    /**
     * @brief generateX генерирует координату X для точки
     * @param index индекс точки
     * @return вернет координату X
     */
    float generateX(const int& index) const;
    /**
     * @brief generateY генерирует координату Y для точки
     * @param index индекс точки
     * @return вернет координату Y
     */
    float generateY(const int& index)const;
    /**
     * @brief touching данный метод проверит входит ли точка в данный контур
     * @param x_ х точки
     * @param y_ у точки
     * @return
     */
    bool touching(const float &x, const float &y)const;
    /**
     * @brief setKord установит указатели на новый центр обьекта
     * @param x указатель на центр по x
     * @param y указатель на центр по у
     */
    void setKord(float *x, float *y,float *engle);
    /**
     * @brief touching данный метод проверит входит ли точка в данный контур
     * @param contur
     * @return
     */
    bool touching(const EContur& contur)const;
    /**
     * @brief touching анологично пред идущему методу но этот метод статичен
     * @param conturA
     * @param x_
     * @param y_
     * @return
     */
    static bool touching(const EContur& conturA, const float &x, const float &y);
    /**
     * @brief touching проверяет столконовения двух обьектов
     * @param conturA
     * @param conturB
     * @return
     */
    static bool touching(const EContur& conturA, EContur& conturB);
    /**
     * @brief addVertix добавит вершину для хит бокса
     * @param vertixItem данные о вершине
     * X-> Radius;  Y-> Ugol (в радианах)
     */
    void addVertix(const EKord& vertixItem);
    /**
     * @brief removeLastVertix удалит последне добавленую вершину
     * @return вернет истину если удалось удалить в пративном случае лож
     */
    bool removeLastVertix();
    /**
     * @brief removeVertix удалит выбранную вершину
     * @param indexVertix индекс удоляемой вершины
     * @return вернет истину в случае удачи в противнос случае лож
     */
    bool removeVertix(const unsigned int indexVertix);
    /**
     * @brief EContur конструктор для режима окружностей
     * @param x указатель на центр обьекта
     * @param y указатель на центр обьекта
     * @param point список точек окружностей (радиусы окружностей)
     */
    explicit EContur(float *x=NULL, float *y=NULL,float *engle=NULL,QVector<EKord> *point=NULL);
    ~EContur();
};
#endif // CONTUR_H
