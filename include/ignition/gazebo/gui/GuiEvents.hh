/*
 * Copyright (C) 2020 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef IGNITION_GAZEBO_GUI_GUIEVENTS_HH_
#define IGNITION_GAZEBO_GUI_GUIEVENTS_HH_


#include <QEvent>
#include <set>

#include <ignition/math/Vector3.hh>
#include "ignition/gazebo/Entity.hh"
#include "ignition/gazebo/config.hh"

namespace ignition
{
namespace gazebo
{
namespace gui {
// Inline bracket to help doxygen filtering.
inline namespace IGNITION_GAZEBO_VERSION_NAMESPACE {
/// \brief Namespace for all events. Refer to the EventManager class for
/// more information about events.
namespace events
{

  class SnapIntervals : public QEvent
  {
    /// \brief Constructor
    /// \param[in] _xyz XYZ snapping values.
    /// \param[in] _rpy RPY snapping values.
    /// \param[in] _scale Scale snapping values.
    public: SnapIntervals(
                math::Vector3d _xyz,
                math::Vector3d _rpy,
                math::Vector3d _scale)
    : QEvent(Type), xyz(_xyz), rpy(_rpy), scale(_scale)
    {
    }

    /// \brief Get the XYZ snapping values.
    /// \return The XYZ snapping values.
    public: math::Vector3d XYZ() const
    {
      return this->xyz;
    }

    /// \brief Get the RPY snapping values.
    /// \return The RPY snapping values.
    public: math::Vector3d RPY() const
    {
      return this->rpy;
    }

    /// \brief Get the scale snapping values.
    /// \return The scale snapping values.
    public: math::Vector3d Scale() const
    {
      return this->scale;
    }

    /// \brief The QEvent representing a snap event occurrence.
    static const QEvent::Type Type = QEvent::Type(QEvent::User);

    /// \brief XYZ snapping values.
    private: math::Vector3d xyz;

    /// \brief RPY snapping values.
    private: math::Vector3d rpy;

    /// \brief RPY snapping values.
    private: math::Vector3d scale;
  };

  class EntitiesSelected : public QEvent
  {
    public: explicit EntitiesSelected(std::set<Entity> &_entities,
                                      bool _fromUser = false)
        : QEvent(Type), entities(_entities), fromUser(_fromUser)
    {
    }
    public: std::set<Entity> Data() const
    {
      return this->entities;
    }
    public: bool FromUser() const
    {
      return this->fromUser;
    }

    static const QEvent::Type Type = QEvent::Type(QEvent::User + 1);
    private: std::set<Entity> entities;
    private: bool fromUser = false;
  };

  class DeselectAllEntities : public QEvent
  {
    public: explicit DeselectAllEntities(bool _fromUser = false)
        : QEvent(Type), fromUser(_fromUser)
    {
    }
    public: bool FromUser() const
    {
      return this->fromUser;
    }
    static const QEvent::Type Type = QEvent::Type(QEvent::User + 2);
    private: bool fromUser = false;
  };
}  // namespace events
}
}  // namespace gui
}  // namespace gazebo
}  // namespace ignition

#endif  // IGNITION_GAZEBO_GUI_GUIEVENTS_HH_
