//#line 2 "/opt/ros/indigo/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
// 
// File autogenerated for the capra_filters package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

#ifndef __capra_filters__PERSPECTIVE_CALIBRATIONCONFIG_H__
#define __capra_filters__PERSPECTIVE_CALIBRATIONCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace capra_filters
{
  class perspective_calibrationConfigStatics;
  
  class perspective_calibrationConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(perspective_calibrationConfig &config, const perspective_calibrationConfig &max, const perspective_calibrationConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const perspective_calibrationConfig &config1, const perspective_calibrationConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, perspective_calibrationConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const perspective_calibrationConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, perspective_calibrationConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const perspective_calibrationConfig &config) const = 0;
      virtual void getValue(const perspective_calibrationConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string name, std::string type, uint32_t level, 
          std::string description, std::string edit_method, T perspective_calibrationConfig::* f) :
        AbstractParamDescription(name, type, level, description, edit_method),
        field(f)
      {}

      T (perspective_calibrationConfig::* field);

      virtual void clamp(perspective_calibrationConfig &config, const perspective_calibrationConfig &max, const perspective_calibrationConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const perspective_calibrationConfig &config1, const perspective_calibrationConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, perspective_calibrationConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const perspective_calibrationConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, perspective_calibrationConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const perspective_calibrationConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const perspective_calibrationConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, perspective_calibrationConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string name, std::string type, int parent, int id, bool s, T PT::* f) : AbstractGroupDescription(name, type, parent, id, s), field(f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, perspective_calibrationConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<perspective_calibrationConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(perspective_calibrationConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("top_left_x"==(*_i)->name){top_left_x = boost::any_cast<int>(val);}
        if("top_left_y"==(*_i)->name){top_left_y = boost::any_cast<int>(val);}
        if("top_right_x"==(*_i)->name){top_right_x = boost::any_cast<int>(val);}
        if("top_right_y"==(*_i)->name){top_right_y = boost::any_cast<int>(val);}
        if("bottom_left_x"==(*_i)->name){bottom_left_x = boost::any_cast<int>(val);}
        if("bottom_left_y"==(*_i)->name){bottom_left_y = boost::any_cast<int>(val);}
        if("bottom_right_x"==(*_i)->name){bottom_right_x = boost::any_cast<int>(val);}
        if("bottom_right_y"==(*_i)->name){bottom_right_y = boost::any_cast<int>(val);}
        if("translation_x"==(*_i)->name){translation_x = boost::any_cast<int>(val);}
        if("translation_y"==(*_i)->name){translation_y = boost::any_cast<int>(val);}
        if("zoom"==(*_i)->name){zoom = boost::any_cast<int>(val);}
        if("input"==(*_i)->name){input = boost::any_cast<std::string>(val);}
        if("output"==(*_i)->name){output = boost::any_cast<std::string>(val);}
      }
    }

    int top_left_x;
int top_left_y;
int top_right_x;
int top_right_y;
int bottom_left_x;
int bottom_left_y;
int bottom_right_x;
int bottom_right_y;
int translation_x;
int translation_y;
int zoom;
std::string input;
std::string output;

    bool state;
    std::string name;

    
}groups;



//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int top_left_x;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int top_left_y;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int top_right_x;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int top_right_y;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int bottom_left_x;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int bottom_left_y;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int bottom_right_x;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int bottom_right_y;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int translation_x;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int translation_y;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int zoom;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      std::string input;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      std::string output;
//#line 218 "/opt/ros/indigo/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("perspective_calibrationConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const perspective_calibrationConfig &__max__ = __getMax__();
      const perspective_calibrationConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const perspective_calibrationConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const perspective_calibrationConfig &__getDefault__();
    static const perspective_calibrationConfig &__getMax__();
    static const perspective_calibrationConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const perspective_calibrationConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void perspective_calibrationConfig::ParamDescription<std::string>::clamp(perspective_calibrationConfig &config, const perspective_calibrationConfig &max, const perspective_calibrationConfig &min) const
  {
    return;
  }

  class perspective_calibrationConfigStatics
  {
    friend class perspective_calibrationConfig;
    
    perspective_calibrationConfigStatics()
    {
perspective_calibrationConfig::GroupDescription<perspective_calibrationConfig::DEFAULT, perspective_calibrationConfig> Default("Default", "", 0, 0, true, &perspective_calibrationConfig::groups);
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.top_left_x = -1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.top_left_x = 1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.top_left_x = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("top_left_x", "int", 0, "", "", &perspective_calibrationConfig::top_left_x)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("top_left_x", "int", 0, "", "", &perspective_calibrationConfig::top_left_x)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.top_left_y = -1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.top_left_y = 1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.top_left_y = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("top_left_y", "int", 0, "", "", &perspective_calibrationConfig::top_left_y)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("top_left_y", "int", 0, "", "", &perspective_calibrationConfig::top_left_y)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.top_right_x = -1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.top_right_x = 1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.top_right_x = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("top_right_x", "int", 0, "", "", &perspective_calibrationConfig::top_right_x)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("top_right_x", "int", 0, "", "", &perspective_calibrationConfig::top_right_x)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.top_right_y = -1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.top_right_y = 1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.top_right_y = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("top_right_y", "int", 0, "", "", &perspective_calibrationConfig::top_right_y)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("top_right_y", "int", 0, "", "", &perspective_calibrationConfig::top_right_y)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.bottom_left_x = -1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.bottom_left_x = 1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.bottom_left_x = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("bottom_left_x", "int", 0, "", "", &perspective_calibrationConfig::bottom_left_x)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("bottom_left_x", "int", 0, "", "", &perspective_calibrationConfig::bottom_left_x)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.bottom_left_y = -1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.bottom_left_y = 1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.bottom_left_y = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("bottom_left_y", "int", 0, "", "", &perspective_calibrationConfig::bottom_left_y)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("bottom_left_y", "int", 0, "", "", &perspective_calibrationConfig::bottom_left_y)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.bottom_right_x = -1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.bottom_right_x = 1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.bottom_right_x = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("bottom_right_x", "int", 0, "", "", &perspective_calibrationConfig::bottom_right_x)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("bottom_right_x", "int", 0, "", "", &perspective_calibrationConfig::bottom_right_x)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.bottom_right_y = -1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.bottom_right_y = 1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.bottom_right_y = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("bottom_right_y", "int", 0, "", "", &perspective_calibrationConfig::bottom_right_y)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("bottom_right_y", "int", 0, "", "", &perspective_calibrationConfig::bottom_right_y)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.translation_x = -1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.translation_x = 1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.translation_x = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("translation_x", "int", 0, "", "", &perspective_calibrationConfig::translation_x)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("translation_x", "int", 0, "", "", &perspective_calibrationConfig::translation_x)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.translation_y = -1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.translation_y = 1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.translation_y = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("translation_y", "int", 0, "", "", &perspective_calibrationConfig::translation_y)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("translation_y", "int", 0, "", "", &perspective_calibrationConfig::translation_y)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.zoom = -1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.zoom = 1500;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.zoom = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("zoom", "int", 0, "", "", &perspective_calibrationConfig::zoom)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<int>("zoom", "int", 0, "", "", &perspective_calibrationConfig::zoom)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.input = "";
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.input = "";
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.input = "";
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<std::string>("input", "str", 0, "Input topic", "", &perspective_calibrationConfig::input)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<std::string>("input", "str", 0, "Input topic", "", &perspective_calibrationConfig::input)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.output = "";
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.output = "";
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.output = "";
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<std::string>("output", "str", 0, "Output topic", "", &perspective_calibrationConfig::output)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(perspective_calibrationConfig::AbstractParamDescriptionConstPtr(new perspective_calibrationConfig::ParamDescription<std::string>("output", "str", 0, "Output topic", "", &perspective_calibrationConfig::output)));
//#line 233 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 233 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(perspective_calibrationConfig::AbstractGroupDescriptionConstPtr(new perspective_calibrationConfig::GroupDescription<perspective_calibrationConfig::DEFAULT, perspective_calibrationConfig>(Default)));
//#line 353 "/opt/ros/indigo/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<perspective_calibrationConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<perspective_calibrationConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<perspective_calibrationConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    perspective_calibrationConfig __max__;
    perspective_calibrationConfig __min__;
    perspective_calibrationConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const perspective_calibrationConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static perspective_calibrationConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &perspective_calibrationConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const perspective_calibrationConfig &perspective_calibrationConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const perspective_calibrationConfig &perspective_calibrationConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const perspective_calibrationConfig &perspective_calibrationConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<perspective_calibrationConfig::AbstractParamDescriptionConstPtr> &perspective_calibrationConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<perspective_calibrationConfig::AbstractGroupDescriptionConstPtr> &perspective_calibrationConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const perspective_calibrationConfigStatics *perspective_calibrationConfig::__get_statics__()
  {
    const static perspective_calibrationConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = perspective_calibrationConfigStatics::get_instance();
    
    return statics;
  }


}

#endif // __PERSPECTIVE_CALIBRATIONRECONFIGURATOR_H__
