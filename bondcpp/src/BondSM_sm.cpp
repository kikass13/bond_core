// Copyright 2018 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*
 * Copyright (c) 2009, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

// Author: Stuart Glaser

/*
 * ex: set ro:
 * DO NOT EDIT.
 * generated by smc (http://smc.sourceforge.net/)
 * from file : BondSM_sm.sm
 */

#include "bondcpp/bond.hpp"
#include "bondcpp/BondSM_sm.hpp"

// Static class declarations.
SM_WaitingForSister SM::WaitingForSister("SM::WaitingForSister", 0);
SM_Alive SM::Alive("SM::Alive", 1);
SM_AwaitSisterDeath SM::AwaitSisterDeath("SM::AwaitSisterDeath", 2);
SM_Dead SM::Dead("SM::Dead", 3);

void BondSMState::ConnectTimeout(BondSMContext & context)
{
  Default(context);
}

void BondSMState::Die(BondSMContext & context)
{
  Default(context);
}

void BondSMState::DisconnectTimeout(BondSMContext & context)
{
  Default(context);
}

void BondSMState::HeartbeatTimeout(BondSMContext & context)
{
  Default(context);
}

void BondSMState::SisterAlive(BondSMContext & context)
{
  Default(context);
}

void BondSMState::SisterDead(BondSMContext & context)
{
  Default(context);
}

void BondSMState::Default(BondSMContext & context)
{
  throw (
          statemap::TransitionUndefinedException(
            context.getState().getName(),
            context.getTransition()));
}

void SM_WaitingForSister::ConnectTimeout(BondSMContext & context)
{
  BondSM & ctxt(context.getOwner());

  (context.getState()).Exit(context);
  context.clearState();
  try {
    ctxt.Death();
    context.setState(SM::Dead);
  } catch (...) {
    context.setState(SM::Dead);
    throw;
  }
  (context.getState()).Entry(context);
}

void SM_WaitingForSister::Die(BondSMContext & context)
{
  BondSM & ctxt(context.getOwner());

  (context.getState()).Exit(context);
  context.clearState();
  try {
    ctxt.Death();
    context.setState(SM::Dead);
  } catch (...) {
    context.setState(SM::Dead);
    throw;
  }
  (context.getState()).Entry(context);
}

void SM_WaitingForSister::SisterAlive(BondSMContext & context)
{
  BondSM & ctxt(context.getOwner());

  (context.getState()).Exit(context);
  context.clearState();
  try {
    ctxt.Connected();
    context.setState(SM::Alive);
  } catch (...) {
    context.setState(SM::Alive);
    throw;
  }
  (context.getState()).Entry(context);
}

void SM_WaitingForSister::SisterDead(BondSMContext & context)
{
  BondSM & ctxt(context.getOwner());

  (context.getState()).Exit(context);
  context.clearState();
  try {
    ctxt.Connected();
    ctxt.SisterDied();
    ctxt.Death();
    context.setState(SM::Dead);
  } catch (...) {
    context.setState(SM::Dead);
    throw;
  }
  (context.getState()).Entry(context);
}

void SM_Alive::Die(BondSMContext & context)
{
  BondSM & ctxt(context.getOwner());

  (context.getState()).Exit(context);
  context.clearState();
  try {
    ctxt.StartDying();
    context.setState(SM::AwaitSisterDeath);
  } catch (...) {
    context.setState(SM::AwaitSisterDeath);
    throw;
  }
  (context.getState()).Entry(context);
}

void SM_Alive::HeartbeatTimeout(BondSMContext & context)
{
  BondSM & ctxt(context.getOwner());

  (context.getState()).Exit(context);
  context.clearState();
  try {
    ctxt.Death();
    context.setState(SM::Dead);
  } catch (...) {
    context.setState(SM::Dead);
    throw;
  }
  (context.getState()).Entry(context);
}

void SM_Alive::SisterAlive(BondSMContext & context)
{
  BondSM & ctxt(context.getOwner());

  (context.getState()).Exit(context);
  context.clearState();
  try {
    ctxt.Heartbeat();
    context.setState(SM::Alive);
  } catch (...) {
    context.setState(SM::Alive);
    throw;
  }
  (context.getState()).Entry(context);
}

void SM_Alive::SisterDead(BondSMContext & context)
{
  BondSM & ctxt(context.getOwner());

  (context.getState()).Exit(context);
  context.clearState();
  try {
    ctxt.SisterDied();
    ctxt.Death();
    context.setState(SM::Dead);
  } catch (...) {
    context.setState(SM::Dead);
    throw;
  }
  (context.getState()).Entry(context);
}

void SM_AwaitSisterDeath::Die(BondSMContext & context)
{
  (context.getState()).Exit(context);
  context.setState(SM::AwaitSisterDeath);
  (context.getState()).Entry(context);
}

void SM_AwaitSisterDeath::DisconnectTimeout(BondSMContext & context)
{
  BondSM & ctxt(context.getOwner());

  (context.getState()).Exit(context);
  context.clearState();
  try {
    ctxt.Death();
    context.setState(SM::Dead);
  } catch (...) {
    context.setState(SM::Dead);
    throw;
  }
  (context.getState()).Entry(context);
}

void SM_AwaitSisterDeath::HeartbeatTimeout(BondSMContext & context)
{
  (context.getState()).Exit(context);
  context.setState(SM::AwaitSisterDeath);
  (context.getState()).Entry(context);
}

void SM_AwaitSisterDeath::SisterAlive(BondSMContext & context)
{
  (context.getState()).Exit(context);
  context.setState(SM::AwaitSisterDeath);
  (context.getState()).Entry(context);
}

void SM_AwaitSisterDeath::SisterDead(BondSMContext & context)
{
  BondSM & ctxt(context.getOwner());

  (context.getState()).Exit(context);
  context.clearState();
  try {
    ctxt.Death();
    context.setState(SM::Dead);
  } catch (...) {
    context.setState(SM::Dead);
    throw;
  }
  (context.getState()).Entry(context);
}

void SM_Dead::ConnectTimeout(BondSMContext & context)
{
  (context.getState()).Exit(context);
  context.setState(SM::Dead);
  (context.getState()).Entry(context);
}

void SM_Dead::Die(BondSMContext & context)
{
  (context.getState()).Exit(context);
  context.setState(SM::Dead);
  (context.getState()).Entry(context);
}

void SM_Dead::DisconnectTimeout(BondSMContext & context)
{
  (context.getState()).Exit(context);
  context.setState(SM::Dead);
  (context.getState()).Entry(context);
}

void SM_Dead::HeartbeatTimeout(BondSMContext & context)
{
  (context.getState()).Exit(context);
  context.setState(SM::Dead);
  (context.getState()).Entry(context);
}

void SM_Dead::SisterAlive(BondSMContext & context)
{
  (context.getState()).Exit(context);
  context.setState(SM::Dead);
  (context.getState()).Entry(context);
}

void SM_Dead::SisterDead(BondSMContext & context)
{
  (context.getState()).Exit(context);
  context.setState(SM::Dead);
  (context.getState()).Entry(context);
}

/*
 * Local variables:
 *  buffer-read-only: t
 * End:
 */
