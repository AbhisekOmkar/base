#include <boost/bind.hpp>
#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <ignition/math/Quaternion.hh>


// ICE utils includes
#include <Ice/Ice.h>
#include <IceUtil/IceUtil.h>
#include <easyiceconfig/EasyIce.h>


//#include <jderobot/motors.h>
#include <jderobot/pose3d.h>

#ifndef POSE3DPIONEER_H
#define	POSE3DPIONEER_H

using namespace ignition;

namespace gazebo {
    
    
    class Pose3D : public ModelPlugin {
    public:
        
        Pose3D();
        
        virtual void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/);
        physics::ModelPtr getModel();
        
        pthread_mutex_t mutex;
        pthread_mutex_t mutexPose3D;
        int count;
        struct pose3d_t {
            float x;
            float y;
            float z;
            float h;
            float q0;
            float q1;
            float q2;
            float q3;
        };
        math::Quaterniond initial_q;
        pose3d_t robotPose3D;
        std::string namePose3D;
        
    private:
        
        void OnUpdate();
        physics::ModelPtr model;
        math::Pose3d position;
        event::ConnectionPtr updateConnection;
        
        
    };
    
}

#endif	/* POSE3D_H */
