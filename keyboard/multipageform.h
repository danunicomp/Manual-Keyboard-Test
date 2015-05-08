#ifndef MULTIPAGEFORM_H
#define MULTIPAGEFORM_H


namespace Ui {
class MultiPageForm;
}

class MultiPageForm : public MultiPageWidget
{
    Q_OBJECT
    
public:
    explicit MultiPageForm(QWidget *parent = 0);
    ~MultiPageForm();
    
private:
    Ui::MultiPageForm *ui;
};

#endif // MULTIPAGEFORM_H
