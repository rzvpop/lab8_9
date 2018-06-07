#pragma once

#include <utility>
#include "event.hpp"
#include "repository.hpp"

class UndoAction
{
public:
    explicit UndoAction() = default;

    UndoAction(const UndoAction&) = delete;
    UndoAction& operator=(const UndoAction&) = delete;

    virtual void ExecuteUndo() = 0;
    // virtual destructor!
    virtual ~UndoAction() = default;
};

class UndoAdd : public UndoAction
{
private:
    Event added_event;
    Repository<Event>& repo;
public:
    explicit UndoAdd(Repository<Event>& _repo, Event e): repo{ _repo }, added_event{std::move(e)} {}
    UndoAdd(const UndoAdd&) = delete;
    UndoAdd& operator=(const UndoAdd&) = delete;
    ~UndoAdd() override = default;

    void ExecuteUndo() override
    {
        this->repo.Remove(added_event);
    }
};

class UndoRemove : public UndoAction
{
private:
    Event deleted_event;
    Repository<Event>& repo;
public:
    explicit UndoRemove(Repository<Event>& _repo, Event e): repo{ _repo }, deleted_event{std::move(e)} {}
    UndoRemove(const UndoRemove&) = delete;
    UndoRemove& operator=(const UndoRemove&) = delete;
    ~UndoRemove() override = default;

    void ExecuteUndo() override
    {
        this->repo.Add(deleted_event);
    }
};

class UndoUpdate : public UndoAction
{
private:
    Event old_event;
    Repository<Event>& repo;
public:
    explicit UndoUpdate(Repository<Event>& _repo, Event e): repo{ _repo }, old_event{std::move(e)} {}
    UndoUpdate(const UndoUpdate&) = delete;
    UndoUpdate& operator=(const UndoUpdate&) = delete;
    ~UndoUpdate() override = default;

    void ExecuteUndo() override
    {
        this->repo.Replace(old_event);
    }
};