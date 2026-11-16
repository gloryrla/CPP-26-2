class User{
private:
    int hp;

public:
    void DecreasedHP(User user) {
        user.hp -= 1;
    }

    int GetHp(User user){
        return user.hp;
    }

    bool CheckUser(User user){
        if (user.hp == 0) {
            return false;
        }

        return true;
    }

};