#ifndef KISSWATCHGROUP_H
#define KISSWATCHGROUP_H

#include "kritapigment_export.h"
#include <QVector>
#include <QMap> // Used to keep track of the last row. Qt doesn't provide a priority queue...
#include "KisSwatch.h"

class KRITAPIGMENT_EXPORT KisSwatchGroup
{
private:
    static quint32 DEFAULT_N_COLUMN;

public:
    typedef QMap<int, KisSwatch> Column;

public:
    KisSwatchGroup();
    void setName(const QString &name) { m_name = name; }
    QString name() const { return m_name; }
    void setNColumns(int nColumns);
    int nColumns() const { return m_colorMatrix.size(); }
    int nRows() const;
    int nColors() const { return m_nColors; }

    const QVector<Column> &colors() const { return m_colorMatrix; }

    /**
     * @brief checkEntry checks if position x and y has an entry
     * @param x
     * @param y
     * @return
     */
    bool checkEntry(int x, int y) const;
    void setEntry(const KisSwatch &e, int x, int y);
    KisSwatch getEntry (int x, int y) const;
    bool removeEntry(int x, int y);

    void clear() { m_colorMatrix.clear(); }

private:
    QString m_name;
    QVector<Column> m_colorMatrix;
    QMap<int, int> m_nRows;
    int m_nColors;
    int m_nLastRowEntries;
};

#endif // KISSWATCHGROUP_H